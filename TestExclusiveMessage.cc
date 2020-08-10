//
// Created by 冉小龙 on 2020-08-10.
//

#include <iostream>
#include <thread>
#include <pulsar/Client.h>
#include <pulsar/MessageBuilder.h>

using namespace pulsar;

int main() {
    std::string lookupUrl = "pulsar://localhost:6650";
    std::string topicName = "test-exclusive-topic-4";
    std::string subName = "test-exclusive-sub-4";
    int numOfMessages = 10;

    ClientConfiguration clientConfig;

    // create client
    Client client(lookupUrl, clientConfig);

    // set consumer config
    ConsumerConfiguration consumerConfig;
    consumerConfig.setConsumerType(ConsumerExclusive);
    consumerConfig.setSubscriptionInitialPosition(InitialPositionEarliest);
    consumerConfig.setSchema(SchemaInfo(STRING, "String", ""));

    // ===========================first send===========================
    // create consumer
    Consumer consumer;
    Result result = client.subscribe(topicName, subName, consumerConfig, consumer);
    if (result != ResultOk) {
        std::cout << "Failed to subscribe: " << result << "\n";
        return -1;
    }

    // set producer config
    ProducerConfiguration producerConfig;
    producerConfig.setSchema(SchemaInfo(STRING, "String", ""));

    // create producer
    Producer producer;
    result = client.createProducer(topicName, producerConfig, producer);
    if (result != ResultOk) {
        std::cout << "Error creating producer: " << result << "\n";
        return -1;
    }

    // send message to topic
    std::string prefix = "msg-exclusive-";
    for (int i = 0; i < numOfMessages; i++) {
        std::string messageContent = prefix + std::to_string(i);
        // Send synchronously
        Message msg = MessageBuilder().setContent(messageContent).build();
        Result res = producer.send(msg);
        std::cout << "Message sent: " << res << " and payload is: " << msg.getDataAsString() << "\n";
    }

    // receive messages from topic
    Message receivedMsg;
    MessageId lastMsgId;
    for (int i = 0; i < numOfMessages; i++) {
        consumer.receive(receivedMsg);
        std::cout << "Received: " << receivedMsg << "  with payload '" << receivedMsg.getDataAsString() << "'" << "\n";
        consumer.acknowledge(receivedMsg);
        lastMsgId = receivedMsg.getMessageId();
        std::cout << "Last message ID: " << lastMsgId << "\n";
    }

    consumer.close();

    // ===========================second send===========================
    // send message again
    for (int i = numOfMessages; i < 2*numOfMessages; i++) {
        std::string messageContent = prefix + std::to_string(i);
        // Send synchronously
        Message msg = MessageBuilder().setContent(messageContent).build();
        Result res = producer.send(msg);
        std::cout << "Message sent: " << res << " and payload is: " << msg.getDataAsString() << "\n";
    }

    // create new consumer
    Consumer newConsumer;
    result = client.subscribe(topicName, subName, consumerConfig, newConsumer);
    if (result != ResultOk) {
        std::cout << "Failed to subscribe: " << result << "\n";
        return -1;
    }

    newConsumer.seek(lastMsgId);

    // Sleeping for 2s to wait for consumer seek
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Slept 2 seconds and open a new consumer to seek it to: " << lastMsgId << "\n";

    // use the new consumer to receive message again
    for (int i = 0; i < numOfMessages; i++) {
        newConsumer.receive(receivedMsg);
        std::cout << "Received again: " << receivedMsg << "  with payload '" << receivedMsg.getDataAsString() << "'" << "\n";
        newConsumer.acknowledge(receivedMsg);
        lastMsgId = receivedMsg.getMessageId();
    }
    newConsumer.close();

    // ===========================third send===========================

    // send message again again
    for (int i = 2*numOfMessages; i < 3*numOfMessages; i++) {
        std::string messageContent = prefix + std::to_string(i);
        // Send synchronously
        Message msg = MessageBuilder().setContent(messageContent).build();
        Result res = producer.send(msg);
        std::cout << "Message sent: " << res << " and payload is: " << msg.getDataAsString() << "\n";
    }

    // create new new consumer
    Consumer newNewConsumer;
    result = client.subscribe(topicName, subName, consumerConfig, newNewConsumer);
    if (result != ResultOk) {
        std::cout << "Failed to subscribe: " << result << "\n";
        return -1;
    }

    newNewConsumer.seek(lastMsgId);

    // Sleeping for 2s to wait for consumer seek
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Slept 2 seconds and open a new new consumer to seek it to: " << lastMsgId << "\n";

    // use the new consumer to receive message again
    for (int i = 0; i < numOfMessages; i++) {
        newNewConsumer.receive(receivedMsg);
        std::cout << "Received again: " << receivedMsg << "  with payload '" << receivedMsg.getDataAsString() << "'" << "\n";
        newNewConsumer.acknowledge(receivedMsg);
        lastMsgId = receivedMsg.getMessageId();
    }


    newNewConsumer.close();
    producer.close();
    client.close();
}


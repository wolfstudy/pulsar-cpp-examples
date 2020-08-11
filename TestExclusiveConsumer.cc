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
    std::string topicName = "test-exclusive-topic";
    std::string subName = "test-exclusive-sub";
    int numOfMessages = 10;

    ClientConfiguration clientConfig;

    // create client
    Client client(lookupUrl, clientConfig);

    // set consumer config
    ConsumerConfiguration consumerConfig;
    consumerConfig.setConsumerType(ConsumerExclusive);
    consumerConfig.setSubscriptionInitialPosition(InitialPositionEarliest);
    consumerConfig.setSchema(SchemaInfo(STRING, "String", ""));

    Consumer consumer;
    Message receivedMsg;
    MessageId lastMsgId;

    while (true) {
        std::cout << "create new consumer " << "\n";
        Result result = client.subscribe(topicName, subName, consumerConfig, consumer);
        if (result != ResultOk) {
            std::cout << "Failed to subscribe: " << result << "\n";
            return -1;
        }

        // receive messages from topic
        for (int i = 0; i < numOfMessages; i++) {
            consumer.receive(receivedMsg);
            std::cout << "Received [" << i << "]: "<< receivedMsg << "  with payload '" << receivedMsg.getDataAsString() << "'" << "\n";
            consumer.acknowledge(receivedMsg);
            lastMsgId = receivedMsg.getMessageId();
        }

//        consumer.seek(lastMsgId);

        // Sleeping for 2s to wait for consumer seek
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Slept 2 seconds and open a new consumer to seek it to: " << lastMsgId << "\n";

        // consumer.unsubscribe();
        consumer.close();
    }
}


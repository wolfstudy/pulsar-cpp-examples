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
    std::string subName = "test-exclusive-sub-4";
    int numOfMessages = 1000;

    ClientConfiguration clientConfig;

    // create client
    Client client(lookupUrl, clientConfig);

    // set producer config
    ProducerConfiguration producerConfig;
    producerConfig.setSchema(SchemaInfo(STRING, "String", ""));

    // create producer
    Producer producer;
    Result result = client.createProducer(topicName, producerConfig, producer);
    if (result != ResultOk) {
        std::cout << "Error creating producer: " << result << "\n";
        return -1;
    }

    // send message to topic
    std::string prefix = "msg-exclusive-";

    while (true) {
        for (int i = 0; i < numOfMessages; i++) {
            std::string messageContent = prefix + std::to_string(i);
            // Send synchronously
            Message msg = MessageBuilder().setContent(messageContent).build();
            Result res = producer.send(msg);
            std::cout << "Message sent: " << res << " and payload is: " << msg.getDataAsString() << "\n";
        }
    }

}


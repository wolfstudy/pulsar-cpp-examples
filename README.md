# pulsar-cpp-examples


Broker version: 2.6.1
Pulsar Client lib version: 2.6.1

## How to use TestExclusiveMessage

1. Run Pulsar standalone

```bash
$ bin/pulsar standalone
```

2. Install pulsar-client-cpp lib

**MacOS**

```bash
$ brew install libpulsar
```

You can also choose to build from pulsar-client-cpp, as follows:

```bash
$ cmake . && make && make install
```

> Please refer to [here](https://pulsar.apache.org/docs/en/develop-cpp/) how to install related dependencies of pulsar-client-cpp

3. Run TestExclusiveMessage.cc

```bash
$ g++ --std=c++11 TestExclusiveMessage.cc -o testExclusiveMsg -I$HOME/github.com/apache/pulsar/pulsar-client-cpp/include -lpulsar -L$HOME/github.com/apache/pulsar/pulsar-client-cpp/lib
$ ./testExclusiveMsg
```

4. Output as follows:

```text
2020-08-10 22:16:11.241 INFO  [0x116a555c0] Client:88 | Subscribing on Topic :test-exclusive-topic-4
2020-08-10 22:16:11.245 INFO  [0x116a555c0] ConnectionPool:85 | Created connection for pulsar://localhost:6650
2020-08-10 22:16:11.255 INFO  [0x70000c1b9000] ClientConnection:343 | [127.0.0.1:50580 -> 127.0.0.1:6650] Connected to broker
2020-08-10 22:16:11.275 INFO  [0x70000c1b9000] HandlerBase:53 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 0] Getting connection from pool
2020-08-10 22:16:11.490 INFO  [0x70000c1b9000] ConsumerImpl:199 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 0] Created consumer on broker [127.0.0.1:50580 -> 127.0.0.1:6650] 
2020-08-10 22:16:11.497 INFO  [0x70000c1b9000] BatchMessageContainer:43 | { BatchContainer [size = 0] [batchSizeInBytes_ = 0] [maxAllowedMessageBatchSizeInBytes_ = 131072] [maxAllowedNumMessagesInBatch_ = 1000] [topicName = persistent://public/default/test-exclusive-topic-4] [producerName_ = ] [batchSizeInBytes_ = 0] [numberOfBatchesSent = 0] [averageBatchSize = 0]} BatchMessageContainer constructed
2020-08-10 22:16:11.497 INFO  [0x70000c1b9000] HandlerBase:53 | [persistent://public/default/test-exclusive-topic-4, ] Getting connection from pool
2020-08-10 22:16:11.519 INFO  [0x70000c1b9000] ProducerImpl:165 | [persistent://public/default/test-exclusive-topic-4, ] Created producer on broker [127.0.0.1:50580 -> 127.0.0.1:6650] 
Message sent: Ok and payload is: msg-exclusive-0
Message sent: Ok and payload is: msg-exclusive-1
Message sent: Ok and payload is: msg-exclusive-2
Message sent: Ok and payload is: msg-exclusive-3
Message sent: Ok and payload is: msg-exclusive-4
Message sent: Ok and payload is: msg-exclusive-5
Message sent: Ok and payload is: msg-exclusive-6
Message sent: Ok and payload is: msg-exclusive-7
Message sent: Ok and payload is: msg-exclusive-8
Message sent: Ok and payload is: msg-exclusive-9
Received: Message(prod=standalone-0-8, seq=0, publish_time=1597068971519, payload_size=15, msg_id=(52,0,-1,0), props={})  with payload 'msg-exclusive-0'
Last message ID: (52,0,-1,0)
Received: Message(prod=standalone-0-8, seq=1, publish_time=1597068971528, payload_size=15, msg_id=(52,1,-1,0), props={})  with payload 'msg-exclusive-1'
Last message ID: (52,1,-1,0)
Received: Message(prod=standalone-0-8, seq=2, publish_time=1597068971538, payload_size=15, msg_id=(52,2,-1,0), props={})  with payload 'msg-exclusive-2'
Last message ID: (52,2,-1,0)
Received: Message(prod=standalone-0-8, seq=3, publish_time=1597068971541, payload_size=15, msg_id=(52,3,-1,0), props={})  with payload 'msg-exclusive-3'
Last message ID: (52,3,-1,0)
Received: Message(prod=standalone-0-8, seq=4, publish_time=1597068971544, payload_size=15, msg_id=(52,4,-1,0), props={})  with payload 'msg-exclusive-4'
Last message ID: (52,4,-1,0)
Received: Message(prod=standalone-0-8, seq=5, publish_time=1597068971548, payload_size=15, msg_id=(52,5,-1,0), props={})  with payload 'msg-exclusive-5'
Last message ID: (52,5,-1,0)
Received: Message(prod=standalone-0-8, seq=6, publish_time=1597068971551, payload_size=15, msg_id=(52,6,-1,0), props={})  with payload 'msg-exclusive-6'
Last message ID: (52,6,-1,0)
Received: Message(prod=standalone-0-8, seq=7, publish_time=1597068971554, payload_size=15, msg_id=(52,7,-1,0), props={})  with payload 'msg-exclusive-7'
Last message ID: (52,7,-1,0)
Received: Message(prod=standalone-0-8, seq=8, publish_time=1597068971561, payload_size=15, msg_id=(52,8,-1,0), props={})  with payload 'msg-exclusive-8'
Last message ID: (52,8,-1,0)
Received: Message(prod=standalone-0-8, seq=9, publish_time=1597068971565, payload_size=15, msg_id=(52,9,-1,0), props={})  with payload 'msg-exclusive-9'
Last message ID: (52,9,-1,0)
2020-08-10 22:16:11.572 INFO  [0x116a555c0] ConsumerImpl:866 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 0] Closing consumer for topic persistent://public/default/test-exclusive-topic-4
2020-08-10 22:16:11.575 INFO  [0x70000c1b9000] ConsumerImpl:920 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 0] Closed consumer 0
Message sent: Ok and payload is: msg-exclusive-10
Message sent: Ok and payload is: msg-exclusive-11
Message sent: Ok and payload is: msg-exclusive-12
Message sent: Ok and payload is: msg-exclusive-13
Message sent: Ok and payload is: msg-exclusive-14
Message sent: Ok and payload is: msg-exclusive-15
Message sent: Ok and payload is: msg-exclusive-16
Message sent: Ok and payload is: msg-exclusive-17
Message sent: Ok and payload is: msg-exclusive-18
Message sent: Ok and payload is: msg-exclusive-19
2020-08-10 22:16:11.608 INFO  [0x116a555c0] Client:88 | Subscribing on Topic :test-exclusive-topic-4
2020-08-10 22:16:11.610 INFO  [0x70000c1b9000] HandlerBase:53 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Getting connection from pool
2020-08-10 22:16:11.636 INFO  [0x70000c1b9000] ConsumerImpl:199 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Created consumer on broker [127.0.0.1:50580 -> 127.0.0.1:6650] 
2020-08-10 22:16:11.636 INFO  [0x70000c1b9000] ConsumerImpl:845 | Broker notification of Closed consumer: 1
2020-08-10 22:16:11.636 INFO  [0x70000c1b9000] HandlerBase:130 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Schedule reconnection in 0.1 s
2020-08-10 22:16:11.642 INFO  [0x70000c1b9000] ConsumerImpl:1068 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Seek successfully
2020-08-10 22:16:11.741 INFO  [0x70000c1b9000] HandlerBase:53 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Getting connection from pool
2020-08-10 22:16:11.776 INFO  [0x70000c1b9000] ConsumerImpl:199 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Created consumer on broker [127.0.0.1:50580 -> 127.0.0.1:6650] 
Slept 2 seconds and open a new consumer to seek it to: (52,9,-1,0)
Received again: Message(prod=standalone-0-8, seq=9, publish_time=1597068971565, payload_size=15, msg_id=(52,9,-1,0), props={})  with payload 'msg-exclusive-9'
Received again: Message(prod=standalone-0-8, seq=10, publish_time=1597068971575, payload_size=16, msg_id=(52,10,-1,0), props={})  with payload 'msg-exclusive-10'
Received again: Message(prod=standalone-0-8, seq=11, publish_time=1597068971578, payload_size=16, msg_id=(52,11,-1,0), props={})  with payload 'msg-exclusive-11'
Received again: Message(prod=standalone-0-8, seq=12, publish_time=1597068971581, payload_size=16, msg_id=(52,12,-1,0), props={})  with payload 'msg-exclusive-12'
Received again: Message(prod=standalone-0-8, seq=13, publish_time=1597068971584, payload_size=16, msg_id=(52,13,-1,0), props={})  with payload 'msg-exclusive-13'
Received again: Message(prod=standalone-0-8, seq=14, publish_time=1597068971588, payload_size=16, msg_id=(52,14,-1,0), props={})  with payload 'msg-exclusive-14'
Received again: Message(prod=standalone-0-8, seq=15, publish_time=1597068971591, payload_size=16, msg_id=(52,15,-1,0), props={})  with payload 'msg-exclusive-15'
Received again: Message(prod=standalone-0-8, seq=16, publish_time=1597068971596, payload_size=16, msg_id=(52,16,-1,0), props={})  with payload 'msg-exclusive-16'
Received again: Message(prod=standalone-0-8, seq=17, publish_time=1597068971599, payload_size=16, msg_id=(52,17,-1,0), props={})  with payload 'msg-exclusive-17'
Received again: Message(prod=standalone-0-8, seq=18, publish_time=1597068971602, payload_size=16, msg_id=(52,18,-1,0), props={})  with payload 'msg-exclusive-18'
2020-08-10 22:16:13.647 INFO  [0x116a555c0] ConsumerImpl:866 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Closing consumer for topic persistent://public/default/test-exclusive-topic-4
2020-08-10 22:16:13.649 INFO  [0x70000c1b9000] ConsumerImpl:920 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 1] Closed consumer 1
Message sent: Ok and payload is: msg-exclusive-20
Message sent: Ok and payload is: msg-exclusive-21
Message sent: Ok and payload is: msg-exclusive-22
Message sent: Ok and payload is: msg-exclusive-23
Message sent: Ok and payload is: msg-exclusive-24
Message sent: Ok and payload is: msg-exclusive-25
Message sent: Ok and payload is: msg-exclusive-26
Message sent: Ok and payload is: msg-exclusive-27
Message sent: Ok and payload is: msg-exclusive-28
Message sent: Ok and payload is: msg-exclusive-29
2020-08-10 22:16:13.773 INFO  [0x116a555c0] Client:88 | Subscribing on Topic :test-exclusive-topic-4
2020-08-10 22:16:13.774 INFO  [0x70000c1b9000] HandlerBase:53 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Getting connection from pool
2020-08-10 22:16:13.789 INFO  [0x70000c1b9000] ConsumerImpl:199 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Created consumer on broker [127.0.0.1:50580 -> 127.0.0.1:6650] 
2020-08-10 22:16:13.790 INFO  [0x70000c1b9000] ConsumerImpl:845 | Broker notification of Closed consumer: 2
2020-08-10 22:16:13.790 INFO  [0x70000c1b9000] HandlerBase:130 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Schedule reconnection in 0.1 s
2020-08-10 22:16:13.834 INFO  [0x70000c1b9000] ConsumerImpl:1068 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Seek successfully
2020-08-10 22:16:13.892 INFO  [0x70000c1b9000] HandlerBase:53 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Getting connection from pool
2020-08-10 22:16:13.905 INFO  [0x70000c1b9000] ConsumerImpl:199 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Created consumer on broker [127.0.0.1:50580 -> 127.0.0.1:6650] 
Slept 2 seconds and open a new new consumer to seek it to: (52,18,-1,0)
Received again: Message(prod=standalone-0-8, seq=18, publish_time=1597068971602, payload_size=16, msg_id=(52,18,-1,0), props={})  with payload 'msg-exclusive-18'
Received again: Message(prod=standalone-0-8, seq=19, publish_time=1597068971605, payload_size=16, msg_id=(52,19,-1,0), props={})  with payload 'msg-exclusive-19'
Received again: Message(prod=standalone-0-8, seq=20, publish_time=1597068973650, payload_size=16, msg_id=(52,20,-1,0), props={})  with payload 'msg-exclusive-20'
Received again: Message(prod=standalone-0-8, seq=21, publish_time=1597068973684, payload_size=16, msg_id=(52,21,-1,0), props={})  with payload 'msg-exclusive-21'
Received again: Message(prod=standalone-0-8, seq=22, publish_time=1597068973709, payload_size=16, msg_id=(52,22,-1,0), props={})  with payload 'msg-exclusive-22'
Received again: Message(prod=standalone-0-8, seq=23, publish_time=1597068973728, payload_size=16, msg_id=(52,23,-1,0), props={})  with payload 'msg-exclusive-23'
Received again: Message(prod=standalone-0-8, seq=24, publish_time=1597068973750, payload_size=16, msg_id=(52,24,-1,0), props={})  with payload 'msg-exclusive-24'
Received again: Message(prod=standalone-0-8, seq=25, publish_time=1597068973755, payload_size=16, msg_id=(52,25,-1,0), props={})  with payload 'msg-exclusive-25'
Received again: Message(prod=standalone-0-8, seq=26, publish_time=1597068973761, payload_size=16, msg_id=(52,26,-1,0), props={})  with payload 'msg-exclusive-26'
Received again: Message(prod=standalone-0-8, seq=27, publish_time=1597068973763, payload_size=16, msg_id=(52,27,-1,0), props={})  with payload 'msg-exclusive-27'
2020-08-10 22:16:15.839 INFO  [0x116a555c0] ConsumerImpl:866 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Closing consumer for topic persistent://public/default/test-exclusive-topic-4
2020-08-10 22:16:15.840 INFO  [0x70000c1b9000] ConsumerImpl:920 | [persistent://public/default/test-exclusive-topic-4, test-exclusive-sub-4, 2] Closed consumer 2
2020-08-10 22:16:15.840 INFO  [0x116a555c0] ProducerImpl:502 | [persistent://public/default/test-exclusive-topic-4, standalone-0-8] Closing producer for topic persistent://public/default/test-exclusive-topic-4
2020-08-10 22:16:15.841 INFO  [0x70000c1b9000] ProducerImpl:545 | [persistent://public/default/test-exclusive-topic-4, standalone-0-8] Closed producer
2020-08-10 22:16:15.841 INFO  [0x116a555c0] ClientImpl:479 | Closing Pulsar client
2020-08-10 22:16:15.841 INFO  [0x116a555c0] ProducerImpl:481 | Producer - [persistent://public/default/test-exclusive-topic-4, standalone-0-8] , [batchMessageContainer = { BatchContainer [size = 0] [batchSizeInBytes_ = 0] [maxAllowedMessageBatchSizeInBytes_ = 131072] [maxAllowedNumMessagesInBatch_ = 1000] [topicName = persistent://public/default/test-exclusive-topic-4] [producerName_ = standalone-0-8] [batchSizeInBytes_ = 0] [numberOfBatchesSent = 30] [averageBatchSize = 1]}]
2020-08-10 22:16:15.841 INFO  [0x116a555c0] BatchMessageContainer:194 | [numberOfBatchesSent = 30] [averageBatchSize = 1]
2020-08-10 22:16:15.841 INFO  [0x116a555c0] ClientConnection:1387 | [127.0.0.1:50580 -> 127.0.0.1:6650] Connection closed
2020-08-10 22:16:15.841 INFO  [0x116a555c0] ClientConnection:238 | [127.0.0.1:50580 -> 127.0.0.1:6650] Destroyed connection
```

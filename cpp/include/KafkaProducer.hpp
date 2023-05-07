#include <iostream>  
#include "KafkaConf.hpp"

class KafkaProducer {

public:
    KafkaProducer(std::string topic, Configuration conf)
        : topic_(topic), config_(std::move(conf)), producer(std::move(conf)) {}

    void Produce(const std::string& message){ // pointer to serialized flatbuffer
        producer.produce(MessageBuilder(topic_).partition(0).payload(message));
    }

private:
    cppkafka::Producer producer;
    std::string topic_;
    Configuration config_;
};
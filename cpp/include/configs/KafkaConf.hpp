#pragma once

#include <cppkafka/cppkafka.h>
using namespace cppkafka;

using cppkafka::Configuration;
using cppkafka::Consumer;
using cppkafka::Message;
using cppkafka::Error;


class KafkaConfig {
public:

  KafkaConfig(){}

  Configuration producerConfig_ = {
      {"bootstrap.servers","localhost:9092"},
      {"enable.idempotence", "0"},
      {"retries", 5},
      {"acks", "all"},
      {"max.in.flight.requests.per.connection", 1},
      {"queue.buffering.max.messages","1048576"},
      {"reconnect.backoff.ms", 10},
      {"reconnect.backoff.max.ms", 30000},
      {"max.poll.interval.ms", 600000},
  };

  Configuration consumerConfig_ = {
      {"bootstrap.servers","localhost:9092"},
      {"auto.offset.reset","earliest"},
      {"enable.auto.commit", false},
      {"api.version.request", true},
      {"reconnect.backoff.ms", 10},
      {"reconnect.backoff.max.ms", 30000},
      {"max.poll.interval.ms", 600000},
      
  };


  auto getConsumerConfig(std::string groupid) {
    consumerConfig_.set("group.id",groupid);
    return consumerConfig_;
  }	

  auto getProducerConfig() {
    return producerConfig_;
  }	

  private:
  std::string group;
};

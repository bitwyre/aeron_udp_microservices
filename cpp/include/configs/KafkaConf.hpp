#pragma once

#include <cppkafka/cppkafka.h>
using namespace cppkafka;

using cppkafka::Configuration;
using cppkafka::Consumer;
using cppkafka::Message;
using cppkafka::Error;


class KafkaConfig {
public:

  KafkaConfig(std::string groupid)
             :group(groupid){}

  Configuration consumerConfig_ = {

      {"bootstrap.servers","localhost:9092"}, // redpanda cluster server
      {"auto.offset.reset","earliest"},
      {"enable.auto.commit", false},
      {"api.version.request", true},
      {"reconnect.backoff.ms", 10},
      {"reconnect.backoff.max.ms", 30000},
      {"max.poll.interval.ms", 600000}, // maximum time between two polls before regarding that as dead consumer 
      
  };


  auto getConsumerConfig() {
    consumerConfig_.set("group.id",group);
    return consumerConfig_;
  }	
  private:
  std::string group;
};

#include <iostream>
#include "KafkaConf.hpp"
#include "TradeEvent_generated.h"

int main(){
    KafkaConfig conf("btcusdt");
    Consumer consumer(conf.getConsumerConfig());
    std::cout << "kafka consumer " << std::endl;

}
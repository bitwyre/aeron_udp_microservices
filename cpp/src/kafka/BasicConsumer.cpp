#include <iostream>
#include "KafkaConf.hpp"
#include "TradeEvent_generated.h"

int main(){
    KafkaConfig conf;
    Consumer consumer(conf.getConsumerConfig("btcusdt"));
    std::cout << "kafka consumer " << std::endl;

    while(true){
        
    }



}
#include <iostream>
#include "KafkaConf.hpp"

int main(){
    KafkaConfig conf("btcusdt");
    Consumer consumer(conf.getConsumerConfig());
    std::cout << "kafka consumer " << std::endl;


}
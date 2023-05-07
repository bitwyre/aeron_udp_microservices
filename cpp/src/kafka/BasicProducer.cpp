#include <iostream>
#include "TradeEvent_generated.h" 
#include <flatbuffers/flatbuffers.h>
#include "KafkaProducer.hpp"
#include "KafkaConf.hpp"
#include <cppkafka/cppkafka.h>
using namespace cppkafka;

using cppkafka::Configuration;
using namespace aeron_udp;

int main(){

    flatbuffers::FlatBufferBuilder builder;

    // Fill in the data for the TradeEvent
    std::string instrument = "BTC/USD";
    std::string base_currency = "BTC";
    std::string quote_currency = "USD";
    uint64_t timestamp = 1234567890;
    std::string trade_id = "1234";
    uint64_t quantity = 1;
    std::string price = "50000";
    std::string value = "5000000000";
    std::string trader_long = "John Doe";
    std::string trader_short = "JD";
    std::string ord_id_long = "5678";
    std::string ord_id_short = "5678S";
    std::string maker = "Jane Doe";
    std::string taker = "JT";
    std::string market = "BTC/USD";
    uint32_t leverage_long = 10;
    uint32_t leverage_short = 20;

    // Create a TradeEvent object with the data
    auto instrument_offset = builder.CreateString(instrument);
    auto base_currency_offset = builder.CreateString(base_currency);
    auto quote_currency_offset = builder.CreateString(quote_currency);
    auto trade_id_offset = builder.CreateString(trade_id);
    auto price_offset = builder.CreateString(price);
    auto value_offset = builder.CreateString(value);
    auto trader_long_offset = builder.CreateString(trader_long);
    auto trader_short_offset = builder.CreateString(trader_short);
    auto ord_id_long_offset = builder.CreateString(ord_id_long);
    auto ord_id_short_offset = builder.CreateString(ord_id_short);
    auto maker_offset = builder.CreateString(maker);
    auto taker_offset = builder.CreateString(taker);
    auto market_offset = builder.CreateString(market);

    auto trade_event = CreateTradeEvent(
        builder,
        instrument_offset,
        base_currency_offset,
        quote_currency_offset,
        timestamp,
        trade_id_offset,
        quantity,
        price_offset,
        value_offset,
        trader_long_offset,
        trader_short_offset,
        ord_id_long_offset,
        ord_id_short_offset,
        maker_offset,
        taker_offset,
        market_offset,
        leverage_long,
        leverage_short
    );

    // flatbuffer serialization
    builder.Finish(trade_event);
    uint8_t* serialized_ptr = builder.GetBufferPointer();
    int BufferSize = builder.GetSize();

    std::string topic = "btcusdt";
    KafkaConfig conf;
    Configuration config = conf.getConsumerConfig(topic);

    KafkaProducer prod(topic,config);
    std::string buffer;
    buffer.assign(serialized_ptr,serialized_ptr+BufferSize);
    
    // Producing events
    while(true){
        prod.Produce(buffer);
    }



}
#include <cstdint>
#include <thread>
#include <csignal>
#include <chrono>
#include "AeronConf.hpp"
#include "util/CommandOptionParser.h"
#include "Aeron.h"
#include "FragmentAssembler.h"
#include "concurrent/SleepingIdleStrategy.h"
#include "TradeEvent_generated.h"
#include "AeronConsumer.hpp"
#include "streamIDmap.hpp"


using namespace aeron::util;
using namespace aeron;
using namespace aeron_udp;

std::int64_t var = 0; 

fragment_handler_t printTradeEvent()
{
    return [&](const AtomicBuffer &buffer, util::index_t offset, util::index_t length, const Header &header)
    {
        auto trade_event = GetTradeEvent(buffer.buffer() + offset);

    //     std::cout
    //         << "Message to stream " << header.streamId() << " from session " << header.sessionId()
    //         << "(" << length << "@" << offset << ") <<"
    //         << "TradeEvent: {"
    //         << "instrument: " << trade_event->instrument()->str() << ", "
    //         << "base_currency: " << trade_event->base_currency()->str() << ", "
    //         << "quote_currency: " << trade_event->quote_currency()->str() << ", "
    //         << "timestamp: " << trade_event->timestamp() << ", "
    //         << "trade_id: " << trade_event->trade_id()->str() << ", "
    //         << "quantity: " << trade_event->quantity() << ", "
    //         << "price: " << trade_event->price()->str() << ", "
    //         << "value: " << trade_event->value()->str() << ", "
    //         << "trader_long: " << trade_event->trader_long()->str() << ", "
    //         << "trader_short: " << trade_event->trader_short()->str() << ", "
    //         << "ord_id_long: " << trade_event->ord_id_long()->str() << ", "
    //         << "ord_id_short: " << trade_event->ord_id_short()->str() << ", "
    //         << "maker: " << trade_event->maker()->str() << ", "
    //         << "taker: " << trade_event->taker()->str() << ", "
    //         << "market: " << trade_event->market()->str() << ", "
    //         << "leverage_long: " << trade_event->leverage_long() << ", "
    //         << "leverage_short: " << trade_event->leverage_short()   
    //         << "}}"
    //         << std::endl;
    // };
        uint64_t now = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        uint64_t latency = now - trade_event->timestamp();
        std::cout << "latency in nanoseconds : " << latency << std::endl;
    };
}

int main(int argc, char **argv)
{   
    AeronConsumer trade_event_consumer("aeron:ipc",StreamIDMap::TradeEvent,printTradeEvent());
    trade_event_consumer.Connect();
    auto start_time = std::chrono::high_resolution_clock::now();
    while(true){
        
        trade_event_consumer.Poll();
    }

    return 0;
}
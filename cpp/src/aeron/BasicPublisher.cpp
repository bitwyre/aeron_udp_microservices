#include <cstdint>
#include <cstdio>
#include <thread>
#include <array>
#include <csignal>
#include <cinttypes>

#include "util/CommandOptionParser.h"
#include "TradeEvent_generated.h" 
#include <flatbuffers/flatbuffers.h>
#include "AeronConf.hpp"
#include "AeronProducer.hpp"
#include "Aeron.h"

using namespace aeron::util;
using namespace aeron;
using namespace aeron_udp;

std::array<std::uint8_t, 200000> buffer;


int main()
{

    // Serialize the data
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


    builder.Finish(trade_event);
    uint8_t* buffers = builder.GetBufferPointer();
    int size = builder.GetSize();

    Context context;
    std::string channel = "aeron:udp?endpoint=localhost:20121";
    int streamid = 3;

    context.newSubscriptionHandler(
        [](const std::string &channel, std::int32_t streamId, std::int64_t correlationId)
        {
            std::cout << "Subscription: " << channel << " " << correlationId << ":" << streamId << std::endl;
        });

    context.availableImageHandler(
        [](Image &image)
        {
            std::cout << "Available image correlationId=" << image.correlationId() << " sessionId=" << image.sessionId();
            std::cout << " at position=" << image.position() << " from " << image.sourceIdentity() << std::endl;
        });

    context.unavailableImageHandler(
        [](Image &image)
        {
            std::cout << "Unavailable image on correlationId=" << image.correlationId() << " sessionId=" << image.sessionId();
            std::cout << " at position=" << image.position() << " from " << image.sourceIdentity() << std::endl;
        });

    std::shared_ptr<Aeron> aeron = Aeron::connect(context);
    
    concurrent::AtomicBuffer srcBuffer;
    srcBuffer.wrap(&buffer[0], buffer.size());


    //store
    srcBuffer.putBytes(0, buffers, size);

    std::int64_t id = aeron->addPublication(channel, 3);

    std::shared_ptr<Publication> publication = aeron->findPublication(id);

    while (!publication)
    {
        std::this_thread::yield();
        publication = aeron->findPublication(id);
    }

    while(true){
        const std::int64_t result = publication->offer(srcBuffer, 0, size);
    
        if (result > 0)
        {
            std::cout << "yay!" << std::endl;
        }
        else if (BACK_PRESSURED == result)
        {
            std::cout << "Offer failed due to back pressure" << std::endl;
        }
        else if (NOT_CONNECTED == result)
        {
            std::cout << "Offer failed because publisher is not connected to a subscriber" << std::endl;
        }
        else if (ADMIN_ACTION == result)
        {
            std::cout << "Offer failed because of an administration action in the system" << std::endl;
        }
        else if (PUBLICATION_CLOSED == result)
        {
            std::cout << "Offer failed because publication is closed" << std::endl;
        }
        else
        {
            std::cout << "Offer failed due to unknown reason " << result << std::endl;
        }

        if (!publication->isConnected())
        {
            std::cout << "No active subscribers detected" << std::endl;
        }

    }
    return 0;
}
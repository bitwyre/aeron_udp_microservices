#pragma once

#include <string>
#include <vector>
#include "Aeron.h"
#include "FragmentAssembler.h"
using namespace aeron;


class AeronConsumer {
public:
    AeronConsumer(const std::string& channel, int streamId, int messageLength) 
        : channel_(channel), streamId_(streamId), messageLength_(messageLength) 
    {
        buffer_.resize(messageLength_);
        srcBuffer_.wrap(buffer_.data(), messageLength_);
    }

    void Connect(){
        aeron_ = Aeron::connect(context);
        subscriptionID = aeron_->addSubscription(channel_, streamId_);
    }

    void Poll() { 
        subscription_ = aeron_->findSubscription(subscriptionID);
        
        while (!subscription_)
        {
            std::this_thread::yield();
            subscription_ = aeron_->findSubscription(subscriptionID);
        }

        FragmentAssembler fragmentAssembler(printTradeEvent());
        fragment_handler_t handler = fragmentAssembler.handler();

        const int fragmentsread = subscription_->poll(handler, FRAGMENTS_LIMIT);
        if (result < 0) {
            std::cerr << "Failed to publish message!" << std::endl;
        }
    }


private:
    Context context;
    static FRAGMENTS_LIMIT = 10;
    std::string channel_;
    int streamId_;
    std::int64_t subscriptionID;
    int messageLength_;
    std::vector<std::uint8_t> buffer_;
    concurrent::AtomicBuffer srcBuffer_;
    std::shared_ptr<Aeron> aeron_;
    std::shared_ptr<Subscription> subscription_;
    
};
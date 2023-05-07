#pragma once

#include <string>
#include <vector>
#include "Aeron.h"
#include "FragmentAssembler.h"
using namespace aeron;


class AeronConsumer {
public:
    AeronConsumer(const std::string& channel, int streamId, fragment_handler_t handle) 
        : channel_(channel), streamId_(streamId), on_message(handle) 
    {
        std::cout << "New Aeron Consumer constructed" << std::endl; 
    }

    void Connect(){
        aeron_ = Aeron::connect(context);
        subscriptionID = aeron_->addSubscription(channel_, streamId_);
        subscription_ = aeron_->findSubscription(subscriptionID);
        while (!subscription_)
        {
            std::this_thread::yield();
            subscription_ = aeron_->findSubscription(subscriptionID);
        }
    }

    void Poll() { 
        const int fragmentsread = subscription_->poll(on_message, FRAGMENTS_LIMIT);
    }


private:
    Context context;
    std::uint16_t FRAGMENTS_LIMIT = 10;
    std::string channel_;
    int streamId_;
    std::int64_t subscriptionID;
    std::shared_ptr<Aeron> aeron_;
    std::shared_ptr<Subscription> subscription_;
    fragment_handler_t on_message;
    
};
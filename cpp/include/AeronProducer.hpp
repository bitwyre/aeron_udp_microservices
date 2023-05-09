#pragma once

#include <string>
#include <vector>
#include "Aeron.h"
using namespace aeron;


class AeronProducer {
public:
    AeronProducer(const std::string& channel, int streamId, int messageLength) 
        : channel_(channel), streamId_(streamId), messageLength_(messageLength) 
    {
        buffer_.resize(messageLength_+20000);
        srcBuffer_.wrap(buffer_.data(), messageLength_);
    }

    void Connect(){
        aeron_ = Aeron::connect(context);
        publicationID = aeron_->addPublication(channel_, streamId_);
        publication_ = aeron_->findPublication(publicationID);
        
        while (!publication_)
        {
            std::this_thread::yield();
            publication_ = aeron_->findPublication(publicationID);
        }
    }

    void sendMessage(const std::uint8_t* ptr) { // pointer to serialized flatbuffer

        srcBuffer_.putBytes(0, ptr, messageLength_);

        const std::int64_t result = publication_->offer(srcBuffer_, 0, messageLength_);
        if (result < 0) {
            std::cerr << "Failed to publish message!" << std::endl;
        }
        else{
            std::cerr << "Published Successfully!" << std::endl;
        }
    }


private:
    Context context;
    std::string channel_;
    int streamId_;
    std::int64_t publicationID;
    int messageLength_;
    std::vector<std::uint8_t> buffer_;
    concurrent::AtomicBuffer srcBuffer_;
    std::shared_ptr<Aeron> aeron_;
    std::shared_ptr<Publication> publication_;
    
};
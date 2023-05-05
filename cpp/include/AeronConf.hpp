#ifndef INCLUDED_AERON_SAMPLES_CONFIGURATION__
#define INCLUDED_AERON_SAMPLES_CONFIGURATION__

#include <string>
#include <cstdint>

namespace aeron { namespace samples { namespace configuration {

const static std::string DEFAULT_CHANNEL = "aeron:udp?endpoint=localhost:20121";
const static std::string DEFAULT_PING_CHANNEL = "aeron:udp?endpoint=localhost:20123";
const static std::string DEFAULT_PONG_CHANNEL = "aeron:udp?endpoint=localhost:20124";
const static std::int32_t DEFAULT_STREAM_ID = 1001;
const static std::int32_t DEFAULT_PING_STREAM_ID = 1002;
const static std::int32_t DEFAULT_PONG_STREAM_ID = 1003;
const static long long DEFAULT_NUMBER_OF_WARM_UP_MESSAGES = 100000;
const static long long DEFAULT_NUMBER_OF_MESSAGES = 10000000;
const static int DEFAULT_MESSAGE_LENGTH = 32;
const static int DEFAULT_LINGER_TIMEOUT_MS = 0;
const static int DEFAULT_FRAGMENT_COUNT_LIMIT = 10;
const static bool DEFAULT_RANDOM_MESSAGE_LENGTH = false;
const static bool DEFAULT_PUBLICATION_RATE_PROGRESS = false;

}}}





#endif
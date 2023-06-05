#include <cstdint>
#include <cstdio>
#include <thread>
#include <chrono>
#include <array>
#include <csignal>
#include <cinttypes>

#include "util/CommandOptionParser.h"
#include "TradeEvent_generated.h" 
#include <flatbuffers/flatbuffers.h>
#include "AeronConf.hpp"
#include "AeronProducer.hpp"
#include "streamIDmap.hpp"
#include "Aeron.h"
#include "aeronmd.h"
#include "EmbeddedAeronMediaDriver.hpp"

using namespace aeron::util;
using namespace aeron;
using namespace aeron_udp;


int main()
{
    EmbeddedMediaDriver driver;
    driver.start();


    return 0;
}
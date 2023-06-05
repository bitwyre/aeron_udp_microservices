## Microservice for Kafka/Redpanda Consumer and Aeron Producer in C++ and Aeron Consumer in Rust

This microservice consists of two separate components: one written in C++ that consumes messages from Kafka/Redpanda and produces messages to Aeron, and another written in Rust that only consumes messages from Aeron.

---
Notes:

For Rust, you want to look at folder RustExamples. The other Rust Folder is a draft state.

After clone, run these commands to install aeron repo:
    cd aeron 
    git submodule update --recursive ". this will install the aeron directory.

the aeron media driver must be operating for aeron programs to work. this can be done on command line or in the program.

The following instructions are for running the Java Media Driver via command line. There is a media driver for Rust and also C++, but the documentation was lacking. I used java media driver mainly for this example development because it was consistent and easy, but it may suffer performance issues.

    after git submodule update and make sure you have java..
        ./gradlew 
        $ java -cp aeron-all/build/libs/aeron-all-${VERSION}.jar io.aeron.driver.MediaDriver

    See (https://github.com/real-logic/aeron/wiki/Running-Samples)

For C++, see example provided in first two lines of cpp/src/aeron/basicPublisher. 
Running basicpublisher.cpp or cpp/src/aeron/mediadriverworkaround will also run C++ media driver.

For Rust, an example is here (https://github.com/UnitedTraders/aeron-rs/blob/master/tests/publish_subscribe.rs) line 229, but i was not able to get it working like this. It basically relies on having an executable (aeronmd) in the directory and runs it.

---

Running RustExamples,

Start media driver.
cd RustExamples/src
cargo run --bin basic_subscriber
cargo run --bin basic_publisher (on seperate terminal)
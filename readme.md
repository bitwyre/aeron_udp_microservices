## Microservice for Kafka/Redpanda Consumer and Aeron Producer in C++ and Aeron Consumer in Rust

This microservice consists of two separate components: one written in C++ that consumes messages from Kafka/Redpanda and produces messages to Aeron, and another written in Rust that only consumes messages from Aeron.
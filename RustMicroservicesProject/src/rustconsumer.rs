//The purpose of this microservice is to consume aeron udp messages, serialized in flatbuffer

use aeron_rs::aeron::SubscriptionBuilder;
use aeron_rs::aeron::Context;
use aeron_rs::aeron::Publication;
use aeron_rs::buffer::AlignedBuffer;
use aeron_rs::utils::errors::AeronError;
use flatbuffers::{FlatBufferBuilder, WIPOffset};
use my_schema::{Message, MessageArgs};
use tokio::stream::StreamExt;
use std::io;

mod my_schema {
    include!("my_schema_generated.rs");
}

#[tokio::main]
async fn main() -> Result<(), AeronError> {
    let aeron_context = aeron::Context::new();
    let subscription = SubscriptionBuilder::new()
        .stream_id(1)
        .channel("aeron:udp?endpoint=localhost:40123")
        .build(&aeron_context)
        .unwrap();

    let mut subscription_stream = subscription.into_stream();
    while let Some(message) = subscription_stream.next().await {
        let message_bytes = message.fragment();
        let message = flatbuffers::root_as_message(message_bytes).unwrap();
        let id = message.id();
        let text = message.text();
        // Process the message
        println!("{}", text);
    }

    Ok(())
}
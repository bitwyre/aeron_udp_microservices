use aeron_rs::aeron::Context;
use aeron_rs::aeron::Publication;
use aeron_rs::buffer::AlignedBuffer;
use aeron_rs::utils::errors::AeronError;
use flatbuffers::{FlatBufferBuilder, WIPOffset};
use my_schema::Message;

fn main() -> Result<(), AeronError> {
    // Set up the Aeron context and create a publication for sending messages
    let ctx = Context::new()?;
    let publication = ctx.add_publication("aeron:udp?endpoint=localhost:20121", 10_000_000)?;

    // Create a FlatBuffer builder and a `Message` struct to send as a message
    let mut builder = FlatBufferBuilder::new();
    let message = Message::create_message(&mut builder, 12345, "Hello, world!");

    // Serialize the `Message` struct to a FlatBuffer
    let message_offset = message.finish(&mut builder);
    builder.finish(message_offset, None);

    // Get a reference to the serialized FlatBuffer bytes
    let buf = builder.finished_data();

    // Create an `AlignedBuffer` for sending the message
    let mut buffer = AlignedBuffer::with_capacity(buf.len());

    // Copy the serialized FlatBuffer bytes into the `AlignedBuffer`
    buffer.as_mut_slice().copy_from_slice(buf);

    // Send the message via the Aeron publication
    publication.offer(&buffer)?;

    Ok(())
}
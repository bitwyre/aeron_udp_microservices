cmake_minimum_required(VERSION 3.16)
project(aeron)

find_package(CppKafka REQUIRED)

add_subdirectory(src)
add_subdirectory(external/aeron)
add_executable(aeron_pub src/aeron/BasicPublisher.cpp)
add_executable(aeron_sub src/aeron/BasicSubscriber.cpp)
add_executable(kafka_cons src/kafka/BasicConsumer.cpp)
add_executable(kafka_prod src/kafka/BasicProducer.cpp)

target_link_libraries(kafka_cons PUBLIC CppKafka::cppkafka)
target_link_libraries(kafka_prod PUBLIC CppKafka::cppkafka)
target_link_libraries(aeron_pub PUBLIC CppKafka::cppkafka)
target_link_libraries(aeron_pub PUBLIC aeron_client)

target_link_libraries(aeron_sub PUBLIC CppKafka::cppkafka)
target_link_libraries(aeron_sub PUBLIC aeron_client)

target_include_directories(aeron_pub PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(aeron_sub PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(kafka_cons PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(kafka_prod PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_include_directories(aeron_pub PUBLIC ${PROJECT_SOURCE_DIR}/include/flatbuffers)
target_include_directories(aeron_sub PUBLIC ${PROJECT_SOURCE_DIR}/include/flatbuffers)
target_include_directories(kafka_cons PRIVATE ${PROJECT_SOURCE_DIR}/include/flatbuffers)
target_include_directories(kafka_prod PRIVATE ${PROJECT_SOURCE_DIR}/include/flatbuffers)

target_include_directories(aeron_pub PUBLIC ${PROJECT_SOURCE_DIR}/include/configs)
target_include_directories(aeron_sub PUBLIC ${PROJECT_SOURCE_DIR}/include/configs)
target_include_directories(kafka_cons PUBLIC ${PROJECT_SOURCE_DIR}/include/configs)
target_include_directories(kafka_prod PUBLIC ${PROJECT_SOURCE_DIR}/include/configs)

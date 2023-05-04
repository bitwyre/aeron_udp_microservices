cmake_minimum_required(VERSION 3.16)
project(aeron_udp)

find_package(CppKafka REQUIRED)

add_subdirectory(src)
add_subdirectory(externel/aeron)
add_executable(pub src/BasicPublisher.cpp)
add_executable(cons src/BasicSubscriber.cpp)

target_link_libraries(pub PUBLIC CppKafka::cppkafka)
target_link_libraries(pub PUBLIC aeron_client)

target_link_libraries(cons PUBLIC CppKafka::cppkafka)
target_link_libraries(cons PUBLIC aeron_client)


cmake_minimum_required(VERSION 3.16)
project(aeron_udp)

find_package(CppKafka REQUIRED)

add_subdirectory(src)
add_subdirectory(externel/aeron)
add_executable(main src/main.cpp)

target_link_libraries(main PUBLIC CppKafka::cppkafka)
target_link_libraries(main PUBLIC aeron_client)


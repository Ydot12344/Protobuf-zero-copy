cmake_minimum_required(VERSION 3.22)

set(PROTO_DIR ${CMAKE_CURRENT_LIST_DIR}/protobuf)
set(PROTO_MSG ${CMAKE_CURRENT_LIST_DIR}/messages)

add_subdirectory(protobuf)
add_subdirectory(googletest)
add_subdirectory(benchmark)

add_subdirectory(proto_gen)
add_subdirectory(bench)


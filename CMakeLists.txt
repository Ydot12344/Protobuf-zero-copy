cmake_minimum_required(VERSION 3.22)

set(PROTO_DIR ${CMAKE_CURRENT_LIST_DIR}/third_party/protobuf)
set(PROTO_MSG ${CMAKE_CURRENT_LIST_DIR}/messages)

add_subdirectory(third_party)
add_subdirectory(proto_gen)
add_subdirectory(bench)
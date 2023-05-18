cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 14) 
project(gen_proto_lib)

add_library(${PROJECT_NAME})

target_include_directories (
    ${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(GLOB proto_srcs "${PROTO_MSG}/*.cc")

target_sources(
    ${PROJECT_NAME} PUBLIC 
    gen_data.cpp
    gen_data.h
    ${proto_srcs}
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    ${PROTO_MSG}
    ${CMAKE_HOME_DIRECTORY}/third_party/json/single_include
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    protobuf::libprotobuf 
    nlohmann_json::nlohmann_json
)
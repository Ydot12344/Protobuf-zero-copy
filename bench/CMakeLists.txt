cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 14) 
project(bench)

# Add config.json to build dir
file(COPY ${CMAKE_CURRENT_LIST_DIR}/configs/config.json DESTINATION ${CMAKE_BINARY_DIR}/bench)
file(GLOB srcs "*.cpp")

add_executable(${PROJECT_NAME})

target_sources(
    ${PROJECT_NAME} PRIVATE 
    ${srcs}
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${CMAKE_BINARY_DIR}/third_party/json/single_include
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    gen_proto_lib 
    protobuf::libprotobuf
    benchmark::benchmark 
    nlohmann_json::nlohmann_json
)
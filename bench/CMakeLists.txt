project(bench)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark gen_proto_lib protobuf::libprotobuf gtest)
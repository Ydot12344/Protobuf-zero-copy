project(bench)

add_executable(${PROJECT_NAME} bench1.cpp bench2.cpp main.cpp)

target_sources(${PROJECT_NAME} PRIVATE bench1.cpp bench2.cpp main.cpp common.h bench1.h)

target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark gen_proto_lib protobuf::libprotobuf gtest)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
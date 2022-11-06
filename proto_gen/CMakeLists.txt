project(proto_gen)

set(CMAKE_CXX_STANDARD 14) 

add_executable(${PROJECT_NAME})
add_subdirectory(lib)

target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROTO_MSG} ./lib)
target_link_libraries(${PROJECT_NAME} PRIVATE protobuf::libprotobuf gen_proto_lib)


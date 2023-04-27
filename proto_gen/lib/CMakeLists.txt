project(gen_proto_lib)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE gen_data.cpp ${PROTO_MSG}/common.pb.cc ${PROTO_MSG}/wraper.pb.cc)
target_include_directories(
    ${PROJECT_NAME} PUBLIC ${PROTO_MSG}
    PUBLIC
    # where top-level project will look for the library's public headers
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    # where external projects will look for the library's public headers
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${PROJECT_NAME} PRIVATE protobuf::libprotobuf nlohmann_json::nlohmann_json)
cmake_minimum_required (VERSION 3.16)

project("protos")

find_package(Protobuf REQUIRED CONFIG)

set(PROTO_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/sources")

list(APPEND PROTO_FILES
    "${CMAKE_CURRENT_LIST_DIR}/test.proto"
)

foreach(proto ${PROTO_FILES})
    get_filename_component(PROTO_NAME_WE ${proto} NAME_WE)

    add_library("${PROTO_NAME_WE}-proto" STATIC OBJECT ${proto})

    protobuf_generate(TARGET "${PROTO_NAME_WE}-proto" 
                      PROTOC_OUT_DIR "${PROTO_OUTPUT_DIR}"
                      IMPORT_DIRS "${CMAKE_CURRENT_LIST_DIR}")

    target_link_libraries("${PROTO_NAME_WE}-proto" PUBLIC 
                                                          protobuf::libprotoc 
                                                          protobuf::libprotobuf 
                                                          protobuf::libprotobuf-lite)
    target_include_directories("${PROTO_NAME_WE}-proto" PUBLIC "$<BUILD_INTERFACE:${PROTO_OUTPUT_DIR}>")
endforeach()
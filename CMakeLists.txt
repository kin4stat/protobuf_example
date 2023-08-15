cmake_minimum_required (VERSION 3.16)

project("protobuf-example")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS NO)

add_subdirectory(protos)

add_executable("protobuf-example" main.cpp)

target_link_libraries("protobuf-example" PRIVATE test-proto)
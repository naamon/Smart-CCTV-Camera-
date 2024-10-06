cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(SecurityCamera10 CXX C)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(SecurityCamera10)
add_subdirectory(tests)
add_subdirectory(cameraRunner)
add_subdirectory(serverRunner)
add_subdirectory(ProtoLib)




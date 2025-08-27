cmake_minimum_required(VERSION 3.14)
project(passgen VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options("-Wall")

set(TESTS_DIR "${CMAKE_SOURCE_DIR}/tests/")

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/passwordgenerator/*.h")

add_executable(passgen "${SRC_FILES}" "${HEADER_FILES}")

target_include_directories(passgen PRIVATE ${CMAKE_SOURCE_DIR}/passwordgenerator/)
target_link_libraries(passgen PRIVATE)


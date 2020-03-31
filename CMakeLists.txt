cmake_minimum_required(VERSION 3.1)
project(earley)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
add_executable(Test tests.cpp Grammar.cpp EarleyAlgo.cpp)
add_test(Test ${Testing_SOURCE_DIR}/bin/testing)

add_executable(practicum main.cpp Grammar.cpp EarleyAlgo.cpp)

target_link_libraries(Test Threads::Threads ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})

set(CMAKE_EXE_LINKER_FLAGS --coverage)
add_definitions(-fprofile-arcs -ftest-coverage)
target_link_libraries(Test -fprofile-arcs)
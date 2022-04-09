cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")



add_executable(vector_test_1  vector_test_1.cpp)
add_executable(vectorList vectorList.cpp)
# add_executable(arrayListWithIterator arrayListWithIterator.cpp)
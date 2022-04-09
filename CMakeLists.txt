# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.17)

project(test)
set(CMAKE_CXX_STANDARD 17)








add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")


add_subdirectory(UsingSTL)
add_subdirectory(arraylist)
add_subdirectory(vectorList)
add_subdirectory(chainlist)



##add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
##add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
#必须位于 add_executable（……） 之前
#
#
#或者
#
#-D CMAKE_CXX_FLAGS="/utf-8"
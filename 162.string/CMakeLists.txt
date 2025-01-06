cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(StringProgram)

add_executable(StringProgram 
  src/main.cpp
  src/my_string/my_string.cpp
  src/interface/interface.cpp
  lib/libstdc++/include.cpp
)

target_link_libraries(StringProgram  
  ${CMAKE_SOURCE_DIR}/include
)

project(TestProgram)

include(FetchContent)
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
FetchContent_MakeAvailable(gtest)

add_executable(TestProgram 
  tests/tests.cpp

  include/my_string/my_string.h
  src/my_string/my_string.cpp
  lib/libstdc++/include.cpp
)

target_link_libraries(TestProgram 
  gtest
)

enable_testing()
add_test(NAME MyTest COMMAND TestProgram)



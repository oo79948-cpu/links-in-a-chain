cmake_minimum_required(VERSION 3.24)

project(links_in_a_chain)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(link_test tests/link_test.cpp src/link.cpp)
add_executable(main main.cpp src/link.cpp)

target_link_libraries(link_test PRIVATE Catch2::Catch2WithMain)

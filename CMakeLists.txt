cmake_minimum_required(VERSION 3.16)

project(DonutTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# What does this do?
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /D_ITERATOR_DEBUG_LEVEL=1")
endif()

add_subdirectory(donut)

add_executable(MAIN
  src/main.cpp)

target_include_directories(MAIN PRIVATE
  donut/include
  donut/thirdparty/glfw/include
  donut/nvrhi/include)

target_link_libraries(MAIN
  donut_app)

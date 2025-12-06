cmake_minimum_required(VERSION 3.5)
project(MSH_SmartHome)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_FILES src/*.cpp)

add_executable(msh ${SRC_FILES})

target_include_directories(msh PRIVATE ${PROJECT_SOURCE_DIR}/include)

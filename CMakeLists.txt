cmake_minimum_required(VERSION 3.25)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled4 main.cpp Graphics.h Graphics.cpp HashMap.h HashMap.cpp song.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics audio REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(untitled4 sfml-graphics sfml-audio)
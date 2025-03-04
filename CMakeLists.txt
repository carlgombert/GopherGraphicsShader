cmake_minimum_required(VERSION 3.29)
project(GopherGraphicsShader)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
include_directories(/opt/homebrew/include)  # Path to Homebrew headers
link_directories(/opt/homebrew/lib)         # Path to Homebrew libraries

add_executable(GopherGraphicsShader main.cpp)
target_link_libraries(GopherGraphicsShader glfw GLEW)
target_link_libraries(GopherGraphicsShader "-framework OpenGL")
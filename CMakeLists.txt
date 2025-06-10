cmake_minimum_required(VERSION 3.10)
project(A VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

# GLFW
find_package(glfw3 REQUIRED)

# Include directories
include_directories(include)
include_directories("/usr/local/include")

# Link directories
link_directories("/usr/local/lib")

add_executable(A main.cpp src/Window.cpp)
target_link_libraries(A glfw GL X11 Xrandr Xi Xxf86vm Xinerama Xcursor pthread dl)

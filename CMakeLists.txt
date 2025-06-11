cmake_minimum_required(VERSION 3.10)
project(A VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: add compile warnings
add_compile_options(-Wall -Wextra -Wpedantic)

# GLFW
find_package(glfw3 REQUIRED)
# other
find_package(X11 REQUIRED)
find_library(XTST_LIBRARY Xtst)

# Include directories
include_directories(include)
include_directories("/usr/local/include")
include_directories(${X11_INCLUDE_DIR})

# Link directories
link_directories("/usr/local/lib")

add_executable(A 
                main.cpp 
                src/A.cpp
                src/OSInfoAbility.cpp
                src/SystemMonitorAbility.cpp
                src/ScreenshotAbility.cpp
                src/MouseControlAbility.cpp
                src/KeyboardControlAbility.cpp
                src/WindowManagerAbility.cpp
                )
target_link_libraries(A glfw GL X11 Xrandr Xi Xxf86vm Xinerama Xcursor pthread dl ${X11_LIBRARIES} ${XTST_LIBRARY})

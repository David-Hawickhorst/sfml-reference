# basic cmake stuff
cmake_minimum_required(VERSION 3.22)
project(sfml_examples)
set(CMAKE_CXX_STANDARD 17)

# add some compiler options
add_compile_options(-Wall -Wextra -pedantic)


# create a target that is an executable called "sfml_examples" and "main.cpp" (and potentially other files)
# will be what are compiled into the executable
add_executable(sfml_examples main.cpp
        drawing/DrawableObject.h
        drawing/Player.cpp
        drawing/Renderer.h
        drawing/Player.h)

# this is how to locate the 3rd party package from your system
find_package(SFML COMPONENTS graphics window system REQUIRED)

# this does the linking of the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
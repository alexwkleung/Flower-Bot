# Minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Project name, version and description
project(Flower-Bot VERSION 1.0 DESCRIPTION "Flower Bot")
 
# Add DPP as dependency
add_subdirectory(src/include/DPP)
# add other dependencies 
 
# Create an executable
add_executable(${PROJECT_NAME}
    src/flowerbot.cpp
    # add other cpp files
)
 
# Linking libraries
target_link_libraries(${PROJECT_NAME}
    dpp
    # link other libs
)
 
# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    src/include/DPP/include
    # add other include directories
)
 
# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
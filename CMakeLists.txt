# CMake entry point
cmake_minimum_required(VERSION 3.8)
set(This qtogl-wviewport)

# Set project name.
project(${This} VERSION 0.0.1 LANGUAGES C CXX)

# QT Specific targets.
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set the standards.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path for QT Creator. 
# This variable needs to be changed for other users according to where and what version of QT they installed.
set(CMAKE_PREFIX_PATH "/Users/vasilecampeanu/Qt/6.2.2/macos/lib/cmake")

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find QT Creator Components
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools OpenGLWidgets REQUIRED)

# This variable is used to initialize the POSITION_INDEPENDENT_CODE property on all the targets.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enables testing for this directory and below. 
enable_testing()

# Store a property of directory scope in the named variable.
get_directory_property(ParentDirectory PARENT_DIRECTORY)
if(ParentDirectory STREQUAL "")
    # Organize applications, libraries, etc. in folders in the IDE.
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Add here external libraries

endif(ParentDirectory STREQUAL "")

# Add subdirectories directly in this repository.
add_subdirectory(wviewport)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
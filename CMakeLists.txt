cmake_minimum_required(VERSION 3.10)

# Set the project name
project(GameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCES
    main.cpp
    Monster.cpp
    Monster.h
    Skills.h
)

# Add the executable
add_executable(GameEngine ${SOURCES})

# Windows-specific settings for Visual Studio
if(WIN32)
    # This prevents the console window from closing immediately after execution
    # when running from Visual Studio (Ctrl+F5)
    set_target_properties(GameEngine PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()

cmake_minimum_required(VERSION 3.24)

project(HjulmundEngine VERSION 0.1.0 LANGUAGES CXX)

option(HJULMUND_BUILD_TESTS "Build Hjulmund Engine tests" ON)

add_library(HjulmundEngine
    Engine/Source/Hjulmund/Core/Assert.cpp
    Engine/Source/Hjulmund/Core/Event.cpp
    Engine/Source/Hjulmund/Core/Logger.cpp
    Engine/Source/Hjulmund/Core/Time.cpp
    Engine/Source/Hjulmund/Platform/Input.cpp
    Engine/Source/Hjulmund/Platform/Window.cpp
    Engine/Source/Hjulmund/Runtime/Application.cpp
    Engine/Source/Hjulmund/Scene/Camera.cpp
)

add_library(Hjulmund::Engine ALIAS HjulmundEngine)

target_include_directories(HjulmundEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Source
)

target_compile_features(HjulmundEngine PUBLIC cxx_std_23)

if(MSVC)
    target_compile_options(HjulmundEngine PRIVATE /W4 /permissive-)
else()
    target_compile_options(HjulmundEngine PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(HJULMUND_BUILD_TESTS)
    enable_testing()
    add_subdirectory(Tests)
endif()

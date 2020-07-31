cmake_minimum_required(VERSION 3.5.1)
project(tera)

set(SOURCES
    src/Console.cpp
    src/MessageBus.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
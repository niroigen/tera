cmake_minimum_required(VERSION 3.5.1)
project(tera)

set(SOURCES
    src/Console.cpp
    src/Graphics.cpp
    src/MessageBus.cpp
    src/main.cpp
)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
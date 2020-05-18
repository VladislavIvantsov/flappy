cmake_minimum_required(VERSION 3.16)
project(flappy)

set(CMAKE_CXX_STANDARD 17)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(vendor/glfw)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if (NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif ()
endif ()

include_directories(headers/
        shaders/
        vendor/glad/include/
        vendor/soil/include/
        vendor/glfw/include/)

file(GLOB VENDORS_SOURCES vendor/glad/src/glad.c
        vendor/soil/src/soil.c)
file(GLOB PROJECT_HEADERS headers/*.hpp)
file(GLOB PROJECT_SOURCES sources/*.cpp)
file(GLOB PROJECT_SHADERS shaders/*.hpp)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
        -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${VENDORS_SOURCES}
        ${PROJECT_SHADERS})

target_link_libraries(${PROJECT_NAME}
        glfw
        ${GLFW_LIBRARIES}
        ${GLAD_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
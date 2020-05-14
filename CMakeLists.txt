cmake_minimum_required(VERSION 3.16)
project(flappy)

set(CMAKE_CXX_STANDARD 17)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(vendor/glfw)

include_directories(vendor/glfw/include/)

find_package (OpenGL REQUIRED)
find_package (GLEW REQUIRED STATIC)

file(GLOB PROJECT_HEADERS headers/*.hpp)
file(GLOB PROJECT_SOURCES sources/*.cpp)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})


add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} GLEW)

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
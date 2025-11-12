cmake_minimum_required(VERSION 4.0)
project(MyProgram)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)

add_custom_target(run
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

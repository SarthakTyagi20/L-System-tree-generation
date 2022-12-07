cmake_minimum_required(VERSION 3.2)

project(Lsystem_tree_generation)
set(TARGET ${CMAKE_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW REQUIRED)

set(SOURCES
	"src/main.cpp"
	"src/lsys.cpp"
	"src/turtle.cpp"
	)

add_executable(${TARGET} ${SOURCES})


include_directories( ${OPENGL_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${OPENGL_LIBRARIES} glfw) 
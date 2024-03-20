# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(ToDo_list)


file(GLOB_RECURSE SOURCES  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" )

file(GLOB_RECURSE REMOVE_CMAKE "build/*")
list(REMOVE_ITEM SOURCES ${REMOVE_CMAKE})

message(${SOURCES})


add_executable(ToDo_list  ${SOURCES} )

# add_custom_target(ToDo_list.bin ALL DEPENDS ToDo_list.axf)


# add_custom_command(TARGET ToDo_list.bin
# COMMAND ${CMAKE_C_OBJCOPY} ARGS -O binary ToDo_list.axf ToDo_list.bin)



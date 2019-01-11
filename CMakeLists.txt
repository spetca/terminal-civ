cmake_minimum_required(VERSION 2.8)
project(terminal_civ)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)

file(GLOB SOURCES "src/*.cpp")

add_executable(termtopia ${SOURCES})

install(TARGETS termtopia DESTINATION /bin)
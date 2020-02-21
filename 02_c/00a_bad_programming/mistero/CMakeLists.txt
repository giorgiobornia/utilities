cmake_minimum_required(VERSION 3.10)

project(mistero LANGUAGES C)

add_executable(mistero main.c)

install(TARGETS mistero RUNTIME DESTINATION bin)

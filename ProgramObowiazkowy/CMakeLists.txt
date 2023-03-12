cmake_minimum_required(VERSION 2.8.12)

project(ProgramObowiazkowy)

add_library(funkcje funkcje.c funkcje.h)

add_executable( main main.c )
target_link_libraries( main funkcje )

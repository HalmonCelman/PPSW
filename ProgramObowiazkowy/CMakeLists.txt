cmake_minimum_required(VERSION 2.8.12)

project(PPSW)

add_library( PPSW_all lancuchy.c lancuchy.h konwersje.c konwersje.h dekodowanie.c dekodowanie.h testy.c testy.h )

add_executable( PPSW main.c )

target_link_libraries( PPSW PPSW_all ) 

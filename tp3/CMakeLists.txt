cmake_minimum_required(VERSION 3.10)
project(tp3 C)

set(CMAKE_C_STANDARD 99)

#add_executable(tp3 exo2_grands_entiers.c exo3_parenthesage.c)
add_executable(tp3 exo3_parenthesage.c)
target_link_libraries(tp3 m)
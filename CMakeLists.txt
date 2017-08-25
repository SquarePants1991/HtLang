cmake_minimum_required(VERSION 3.7)
project(HtLang)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ./src/bison.c ./src/lex.c bison.y lex.l)
add_executable(HtLang ${SOURCE_FILES})

add_custom_target(CompileParser)
add_custom_command(TARGET CompileParser PRE_BUILD
        COMMAND rm -rf ./src
        COMMAND mkdir ./src
        COMMAND flex -o ./src/lex.c ${CMAKE_CURRENT_SOURCE_DIR}/lex.l
        COMMAND bison -o ./src/bison.c -dv ${CMAKE_CURRENT_SOURCE_DIR}/bison.y)

add_dependencies(HtLang CompileParser)
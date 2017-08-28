cmake_minimum_required(VERSION 3.7.2)
project(HtLang)

message(${CMAKE_SOURCE_DIR})
add_custom_target(CompileCC)
add_custom_command(TARGET CompileCC
        COMMAND sh ${CMAKE_SOURCE_DIR}/src/analyzer/gen_analyzer.sh ${CMAKE_SOURCE_DIR})

file(GLOB MainSrc
        ./src/*.h
        ./src/*.c
        ./src/**/*.h
        ./src/**/*.c
        ./src/analyzer/bison.c)

add_executable(HTLang ${MainSrc})
add_dependencies(HTLang CompileCC)

file(GLOB UtilsSrc
        ./src/utils/*.h
        ./src/utils/*.c)

include_directories(./src)
add_executable(HTStringTest ./test/HTStringTest.c ${UtilsSrc})
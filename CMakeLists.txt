cmake_minimum_required(VERSION 2.8.2)
project(HtLang)

set(CMAKE_C_STANDARD 99)

file(GLOB MainSrc
        ./src/*.h
        ./src/*.c
        ./src/**/*.h
        ./src/**/*.c)

add_executable(HTLang ${MainSrc})

file(GLOB UtilsSrc
        ./src/utils/*.h
        ./src/utils/*.c)

include_directories(./src)
add_executable(HTStringTest ./test/HTStringTest.c ${UtilsSrc})
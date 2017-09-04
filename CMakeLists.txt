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
        ./src/analyzer/bison.c
        src/htlang.c)

add_executable(HTLang ${MainSrc})
add_dependencies(HTLang CompileCC)

file(GLOB UtilsSrc
        ./src/utils/*.h
        ./src/utils/*.c)

include_directories(./src)
add_executable(HTStringTest ./test/HTStringTest.c ${UtilsSrc})

add_executable(HTTypeTest ./test/HTTypeTest.c ${UtilsSrc})

add_executable(HTListTest ./test/HTListTest.c ${UtilsSrc})

add_executable(HTVariableTest ./test/HTVariableTest.c src/compiler/HTVariable.c ${UtilsSrc})

add_executable(HTExpressionTest ./test/HTExpressionTest.c src/compiler/HTVariable.h src/compiler/HTExpression.c ${UtilsSrc})

add_executable(HTStatementTest ./test/HTStatementTest.c src/compiler/HTExpression.c src/compiler/HTStatement.c src/compiler/HTVariable.c ${UtilsSrc})

add_executable(HTCompilerTest
        ./test/HTCompilerTest.c
        src/compiler/HTVariable.h
        src/compiler/HTExpression.c
        src/compiler/HTStatement.c
        src/compiler/HTCompiler.c ${UtilsSrc})



### Test Executor
add_executable(HTExpressionEvalTest
        ./test/HTExpressionEvalTest.c
        src/compiler/HTVariable.c
        src/compiler/HTExpression.c
        src/compiler/HTStatement.c
        src/compiler/HTCompiler.c
        src/executor/HTExpressionEval.c
        ${UtilsSrc})

add_executable(HTExecutorTest
        ./test/HTExecutorTest.c
        src/compiler/HTVariable.c
        src/compiler/HTExpression.c
        src/compiler/HTStatement.c
        src/compiler/HTCompiler.c
        src/executor/HTExpressionEval.c
        src/executor/HTExecutor.c
        ${UtilsSrc})
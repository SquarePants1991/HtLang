#!/bin/sh
flex -o ./src/lex.c ./lex.l
bison -o ./src/bison.c -dv ./bison.y
cc -o ./bin/calc ./src/lex.c ./src/bison.c
./bin/calc
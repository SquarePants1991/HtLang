#!/bin/sh
flex -o "$1/src/analyzer/lex.c" "$1/src/analyzer/lex.l"
bison -o "$1/src/analyzer/bison.c" -dv "$1/src/analyzer/bison.y"
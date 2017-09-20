#!/usr/bin/env bash
for f in $1*
do
    if [[ "${f}" == *.ht ]]
    then
        printf "\e[1;95m Test ${f} \e[0m \n"
        ../cmake-build-debug/HTLang "${f}" 1 0
    fi
done
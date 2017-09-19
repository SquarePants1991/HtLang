#!/usr/bin/env bash
for f in ./*
do
    if [[ "${f}" == *.ht ]]
    then
        echo "Test ${f}"
        ../cmake-build-debug/HTLang "${f}"
    fi
done
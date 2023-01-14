#!/bin/bash

CC=clang++
FLAGS="-Wall -Wextra -Werror"
DEBUG=""
GREEN="\033[0;32m"
NC="\033[0m"

while getopts dvmsarp flag
do
    case "${flag}" in
        d) DEBUG="debug";;
        v) $CC $FLAGS vector/vector_tests.cpp -o vector/vector_tests  && ./vector/vector_tests $DEBUG > report.md;;
        m) $CC $FLAGS map/map_tests.cpp -o map/map_tests  && ./map/map_tests $DEBUG > report.md;;
        s) $CC $FLAGS stack/stack.cpp -o stack/stack_tests && ./stack/stack_tests $DEBUG > report.md;;
        a) $CC $FLAGS algorithms/algorithms_tests.cpp -o algorithms/algorithms_tests && ./algorithms/algorithms_tests $DEBUG  > report.md;;
        r) $CC $FLAGS reverse_iterator/reverse_iterator.cpp -o reverse_iterator/reverse_iterator_tests && ./reverse_iterator/reverse_iterator_tests $DEBUG  > report.md;;
        p) $CC $FLAGS pair/pair_tests.cpp -o pair/pair_tests && ./pair/pair_tests $DEBUG  > report.md;;
    esac
done

echo "${GREEN}Results generated in report.md file${NC}"
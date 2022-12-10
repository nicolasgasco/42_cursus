CC=clang++
FLAGS="-Wall -Wextra -Werror"
DEBUG=""

while getopts dvsarp flag
do
    case "${flag}" in
        d) DEBUG="debug";;
        v) $CC $FLAGS vector/vector_tests.cpp -o vector/vector_tests  && ./vector/vector_tests $DEBUG;;
        s) $CC $FLAGS stack/stack.cpp -o stack/stack_tests && ./stack/stack_tests $DEBUG;;
        a) echo "algorithms";;
        r) echo "reverse iterator";;
        p) echo "pair";;
    esac
done
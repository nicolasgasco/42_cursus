CC=clang++
FLAGS="-Wall -Wextra -Werror"
DEBUG=""

while getopts dvsarp flag
do
    case "${flag}" in
        d) DEBUG="debug";;
        v) $CC $FLAGS vector/vector_tests.cpp -o vector/vector_tests  && ./vector/vector_tests $DEBUG;;
        s) $CC $FLAGS stack/stack.cpp -o stack/stack_tests && ./stack/stack_tests $DEBUG;;
        a) $CC $FLAGS algorithms/algorithms_tests.cpp -o algorithms/algorithms_tests && ./algorithms/algorithms_tests $DEBUG;;
        r) $CC $FLAGS reverse_iterator/reverse_iterator.cpp -o reverse_iterator/reverse_iterator_tests && ./reverse_iterator/reverse_iterator_tests $DEBUG;;
        p) $CC $FLAGS pair/pair_tests.cpp -o pair/pair_tests && ./pair/pair_tests $DEBUG;;
    esac
done
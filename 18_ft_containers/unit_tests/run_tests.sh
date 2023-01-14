#!/bin/bash

buildHtmlFile() {
    HTML_FILE="report.html"
    
    echo '
<!DOCTYPE html>
<html lang="en">
  <meta charset="UTF-8">
  <title>Containers - Unit tests</title>
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <link rel="icon" href="data:image/svg+xml,<svg xmlns=%22http://www.w3.org/2000/svg%22 viewBox=%220 0 100 100%22><text y=%22.9em%22 font-size=%2290%22>🧪</text></svg>">
  <style>
    body {
        font-family: "Roboto", sans-serif;
        background-color: #202124;
        color: #F5F9FF;
        font-weight: bold;
        line-height: 1.6;
    }
    h1 {
        position: fixed;
        top: 0;
        left: 50%;
        transform: translateX(-50%);
        margin: 0;
    }

    h2 {
        display: inline-block;
        font-size: 1.3rem;
        margin: 0;
        margin: 10px;
    }

    details > div {
        margin-left: 25px;
    }

    p {
        position: fixed;
        top: 5px;
        right: 5px;
        margin: 0;
    }
  </style>
  <script src=""></script>
  <body>
    ' > $HTML_FILE;
    
    sed -e 's/$/<br>/g' -e 's/<\/h1><br>/<\/h1>/g' -e 's/<h2/<\/details><details><h2/g' -e 's/<h2/<summary><h2/g' -e 's/<\/h2>/<\/h2><\/summary>/g' -e 's/<\/summary>/<\/summary><div>/g' -e 's/<\/details>/<\/div><\/details>/g' $1 >> $HTML_FILE;
    echo '</details>' >> $HTML_FILE;
    echo '<p><small>ft_containers project unit tests by Nicolas Gasco</small></p>
  </body>
</html>
    ' >> $HTML_FILE;
}


CC=clang++
FLAGS="-Wall -Wextra -Werror"
DEBUG=""
REPORT_FILE="report.md"

while getopts dvmsarp flag
do
    case "${flag}" in
        d) DEBUG="debug";;
        v) $CC $FLAGS vector/vector_tests.cpp -o vector/vector_tests  && ./vector/vector_tests $DEBUG > $REPORT_FILE;;
        m) $CC $FLAGS map/map_tests.cpp -o map/map_tests  && ./map/map_tests $DEBUG > $REPORT_FILE;;
        s) $CC $FLAGS stack/stack.cpp -o stack/stack_tests && ./stack/stack_tests $DEBUG > $REPORT_FILE;;
        a) $CC $FLAGS algorithms/algorithms_tests.cpp -o algorithms/algorithms_tests && ./algorithms/algorithms_tests $DEBUG  > $REPORT_FILE;;
        r) $CC $FLAGS reverse_iterator/reverse_iterator.cpp -o reverse_iterator/reverse_iterator_tests && ./reverse_iterator/reverse_iterator_tests $DEBUG  > $REPORT_FILE;;
        p) $CC $FLAGS pair/pair_tests.cpp -o pair/pair_tests && ./pair/pair_tests $DEBUG  > $REPORT_FILE;;
    esac
done

GREEN="\033[0;32m"
NC="\033[0m"
echo "${GREEN}Results generated in ${REPORT_FILE} file${NC}"

buildHtmlFile $REPORT_FILE
echo "${GREEN}${HTML_FILE} file generated${NC}"
echo "Opening results in default browser..."
open $HTML_FILE

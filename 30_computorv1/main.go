package main

import (
	"fmt"
	"log"
	"os"

	"computorv1/internal/parser"
	"computorv1/internal/reducer"
)

func main() {
	args := os.Args[1:]
	argsLen := len(args)

	if argsLen != 1 {
		log.Fatal("Please enter exactly 1 argument")
	}

	input := args[0]
	parsingChunks, err := parser.Parser(input)
	if err != nil {
		log.Fatal(err)
	}

	reduced, err := reducer.Reducer(parsingChunks)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("reduced", reduced)
}

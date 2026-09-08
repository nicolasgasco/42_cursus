package main

import (
	"fmt"
	"log"
	"os"

	"computorv1/internal/parser"
)

func main() {
	args := os.Args[1:]
	argsLen := len(args)

	if argsLen != 1 {
		log.Fatal("Please enter exactly 1 argument")
		os.Exit(1)
	}

	input := args[0]
	parsingChunks, err := parser.Parser(input)
	if err != nil {
		log.Fatal(err)
		os.Exit(1)
	}

	fmt.Println("Parsing chunks: ", parsingChunks)
}

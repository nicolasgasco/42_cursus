package main

import (
	"fmt"
	"log"
    "os"
	"parser"
)

func main() {
    args := os.Args[1:]
	argsLen := len(args)

	if argsLen != 1 {
		log.Fatal("Please enter exactly 1 argument")
		os.Exit(1)
	}

	input := args[0]
	Parser(input)
}
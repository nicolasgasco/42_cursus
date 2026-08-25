package main

import (
	"fmt"
	"log"
    "os"
)

func main() {
    args := os.Args[1:]
	argsLen := len(args)

	if argsLen != 1 {
		log.Fatal("Please enter exactly 1 argument")
		os.Exit(1)
	}

	fmt.Println("Input: ", args[0])
}
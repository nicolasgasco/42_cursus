package main

import (
	"bufio"
	"fmt"
	"log"
	"os"

	"computorv1/internal/computer"
	"computorv1/internal/parser"
	"computorv1/internal/printer"
	"computorv1/internal/reducer"
	"computorv1/internal/validator"
)

func main() {
	args := os.Args[1:]
	argsLen := len(args)

	var input string

	switch argsLen {
	case 0:
		scanner := bufio.NewScanner(os.Stdin)
		if !scanner.Scan() {
			if err := scanner.Err(); err != nil {
				log.Fatal(err)
			}
			log.Fatal("Please enter an equation")
		}

		input = scanner.Text()
		if input == "" {
			log.Fatal("Please enter an equation")

		}
	case 1:
		input = args[0]
	default:
		log.Fatal("Please enter exactly 1 argument")
	}

	parsingChunks, err := parser.Parser(input)
	if err != nil {
		log.Fatal(err)
	}

	reduced, err := reducer.Reducer(parsingChunks)
	if err != nil {
		log.Fatal(err)
	}

	errors := validator.Validator(reduced)

	var results []complex128

	noErrors := len(errors) == 0
	if noErrors {
		results, err = computer.Computer(reduced)
		if err != nil {
			log.Fatal(err)
		}
	}

	output := printer.Print(reduced, errors, results)
	fmt.Println(output)
}

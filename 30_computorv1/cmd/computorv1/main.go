package main

import (
	"fmt"
	"os"
)

func validateArgs(args []string) error {
	if len(args) == 0 {
		return fmt.Errorf("please insert at least 1 argument")
	} else if len(args) > 1 {
		return fmt.Errorf("please insert only 1 argument")
	}
	return nil
}

func main() {
	if err := validateArgs(os.Args[1:]); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}

	fmt.Printf("Arguments: %v\n", os.Args[1:])
}

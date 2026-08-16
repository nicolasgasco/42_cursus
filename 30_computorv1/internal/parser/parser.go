package parser

import "fmt"

func Parse(input string) (string, error) {
	if input == "" {
		return "", fmt.Errorf("parsing: empty expression")
	}
	return input, nil
}

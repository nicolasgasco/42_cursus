package parser

import (
	"fmt"
	"strings"
)

func Parse(input string) (string, error) {
	if input == "" {
		return "", fmt.Errorf("parsing: empty expression")
	}

	halves := strings.Split(input, EqualSign)
	fmt.Println(halves)

	return input, nil
}

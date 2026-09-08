package parser

import (
	"errors"
	"strconv"
	"strings"
)

func Parser(input string) ([]ParsingChunk, error) {
	halves := strings.Split(input, "=")

	if len(halves) != 2 {
		return nil, errors.New("parsing: missing equal sign")
	}

	chunks := make([]ParsingChunk, 0)

	for i, half := range halves {
		isRightHandSide := i != 0
		halfChunks, err := parseHalf(half, isRightHandSide)
		if err != nil {
			return nil, err
		}
		chunks = append(chunks, halfChunks...)
	}

	return chunks, nil
}

func parseHalf(input string, isRightHandSide bool) ([]ParsingChunk, error) {
	chunks := make([]ParsingChunk, 0, len(input))

	start := 0
	for i, char := range input {
		if char == '+' || char == '-' {
			rawChunk := strings.Trim(input[start:i], " ")
			chunk, err := parseChunk(rawChunk)
			if err != nil {
				return nil, err
			}

			chunks = append(chunks, chunk)
			start = i
		}

		if i == len(input)-1 {
			rawChunk := strings.Trim(input[start:i+1], " ")
			chunk, err := parseChunk(rawChunk)
			if isRightHandSide {
				chunk.coefficient *= -1
			}

			if err != nil {
				return nil, err
			}

			chunks = append(chunks, chunk)
		}
	}

	return chunks, nil
}

func parseChunk(input string) (ParsingChunk, error) {
	input = strings.ReplaceAll(input, " ", "")
	chunk := ParsingChunk{}

	chunks := strings.Split(input, "*")

	coefficientString := chunks[0]
	coefficient, err := strconv.ParseFloat(coefficientString, 32)
	if err != nil {
		return ParsingChunk{}, errors.New("parsing: invalid coefficient")
	}
	chunk.coefficient = coefficient

	exponentString := chunks[1][len(chunks[1])-1:]
	exponent, err := strconv.ParseInt(exponentString, 10, 32)
	if err != nil {
		return ParsingChunk{}, errors.New("parsing: invalid exponent: " + exponentString)
	}
	chunk.exponent = int(exponent)

	return chunk, nil
}

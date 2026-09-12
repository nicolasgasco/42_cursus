package parser

import (
	"errors"
	"strconv"
	"strings"

	"computorv1/internal/model"
)

func Parser(input string) ([]model.ParsingChunk, error) {
	halves := strings.Split(input, "=")

	if len(halves) != 2 {
		return nil, errors.New("parsing: missing equal sign")
	}

	chunks := make([]model.ParsingChunk, 0)

	for i, half := range halves {
		isRightHandSide := i != 0

		if isZeroRightHandSide := isRightHandSide && strings.TrimSpace(half) == "0"; isZeroRightHandSide {
			continue
		}

		halfChunks, err := parseHalf(half, isRightHandSide)
		if err != nil {
			return nil, err
		}
		chunks = append(chunks, halfChunks...)
	}

	return chunks, nil
}

func parseHalf(input string, isRightHandSide bool) ([]model.ParsingChunk, error) {
	chunks := make([]model.ParsingChunk, 0, len(input))

	start := 0
	for i, char := range input {
		mathSignFound := char == '+' || char == '-'
		if mathSignFound {
			rawChunk := strings.Trim(input[start:i], " ")
			chunk, err := parseChunk(rawChunk)
			if err != nil {
				return nil, err
			}

			if isRightHandSide {
				chunk.Coefficient *= -1
			}

			chunks = append(chunks, chunk)
			start = i
		}

		isEndOfString := i == len(input)-1
		if isEndOfString {
			rawChunk := strings.Trim(input[start:i+1], " ")
			chunk, err := parseChunk(rawChunk)
			if err != nil {
				return nil, err
			}

			if isRightHandSide {
				chunk.Coefficient *= -1
			}

			chunks = append(chunks, chunk)
		}
	}

	return chunks, nil
}

func parseChunk(input string) (model.ParsingChunk, error) {
	input = strings.ReplaceAll(input, " ", "")
	chunk := model.ParsingChunk{}

	chunks := strings.Split(input, "*")

	coefficientString := chunks[0]
	coefficient, err := strconv.ParseFloat(coefficientString, 64)
	if err != nil {
		return model.ParsingChunk{}, errors.New("parsing: invalid coefficient")
	}
	chunk.Coefficient = coefficient

	exponentString := chunks[1][len(chunks[1])-1:]
	exponent, err := strconv.ParseInt(exponentString, 10, 32)
	if err != nil {
		return model.ParsingChunk{}, errors.New("parsing: invalid exponent: " + exponentString)
	}
	chunk.Exponent = int(exponent)

	return chunk, nil
}

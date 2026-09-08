package reducer

import (
	"computorv1/internal/model"
)

func Reducer(input []model.ParsingChunk) ([]model.ParsingChunk, error) {
	byExponent := make(map[int]float64)

	for _, chunk := range input {
		byExponent[chunk.Exponent] += chunk.Coefficient
	}

	reduced := make([]model.ParsingChunk, 0, len(byExponent))
	for exponent, coefficient := range byExponent {
		if exponent == 0 {
			continue
		}

		reduced = append(reduced, model.ParsingChunk{
			Coefficient: coefficient,
			Exponent:    exponent,
		})
	}

	return reduced, nil
}

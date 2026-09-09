package reducer

import (
	"computorv1/internal/model"
	"sort"
)

func Reducer(input []model.ParsingChunk) ([]model.ParsingChunk, error) {
	byExponent := make(map[int]float64)

	for _, chunk := range input {
		byExponent[chunk.Exponent] += chunk.Coefficient
	}

	reduced := make([]model.ParsingChunk, 0, len(byExponent))
	for exponent, coefficient := range byExponent {
		reduced = append(reduced, model.ParsingChunk{
			Coefficient: coefficient,
			Exponent:    exponent,
		})
	}

	sort.Slice(reduced, func(i, j int) bool {
		return reduced[i].Exponent < reduced[j].Exponent
	})

	return reduced, nil
}

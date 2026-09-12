package validator

import (
	"computorv1/internal/model"
)

func Validator(input []model.ParsingChunk) []model.ValidationError {
	errors := make([]model.ValidationError, 0)

	if !isDegreeValid(input) {
		errors = append(errors, model.ValidationOverDegreeMax)
	}

	return errors
}

func isDegreeValid(input []model.ParsingChunk) bool {
	maxDegree := 0
	for _, chunk := range input {
		if chunk.Coefficient != 0 {
			maxDegree = max(maxDegree, chunk.Exponent)
		}
	}

	return maxDegree <= 2
}

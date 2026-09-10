package computer

import (
	"computorv1/internal/model"
	"errors"
	"math"
)

func Computer(input []model.ParsingChunk) ([]float64, error) {
	degree := 0
	for _, chunk := range input {
		degree = max(degree, chunk.Exponent)
	}

	switch degree {
	case 0:
		if len(input) != 1 {
			return nil, errors.New("computing: unsupported function")
		}

		return []float64{solveZeroDegree(input[0])}, nil
	default:
		return nil, errors.New("computing: unsupported degree")
	}
}

func solveZeroDegree(chunk model.ParsingChunk) float64 {
	if chunk.Coefficient == 0 {
		return math.Inf(1)
	}

	return math.Inf(-1)
}

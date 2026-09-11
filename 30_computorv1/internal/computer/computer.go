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
			return nil, errors.New("computing: malformed function")
		}

		result := solveZeroDegree(input[0])
		return []float64{result}, nil
	case 1:
		if len(input) != 2 {
			return nil, errors.New("computing: malformed function")
		}

		result := solveFirstDegree(input)
		return []float64{result}, nil
	default:
		return nil, errors.New("computing: not implemented yet")
	}
}

func solveFirstDegree(chunks []model.ParsingChunk) float64 {
	a0 := chunks[0].Coefficient
	a1 := chunks[1].Coefficient

	if a0 != 0 && a1 == 0 {
		return math.Inf(-1)
	} else if a0 == 0 && a1 == 0 {
		return math.Inf(1)
	} else {
		return -1 * a0 / a1
	}
}

func solveZeroDegree(chunk model.ParsingChunk) float64 {
	if chunk.Coefficient == 0 {
		return math.Inf(1)
	}

	return math.Inf(-1)
}

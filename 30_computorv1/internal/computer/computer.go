package computer

import (
	"computorv1/internal/model"
	"computorv1/internal/util"
	"errors"
	"math"
)

func Computer(input []model.ParsingChunk) ([]complex128, error) {
	degree := 0
	for _, chunk := range input {
		if !util.IsZero(chunk.Coefficient) {
			degree = max(degree, chunk.Exponent)
		}
	}

	switch degree {
	case 0:
		if len(input) < 1 {
			return nil, errors.New("computing: malformed function")
		}

		result := solveZeroDegree(input[0])
		return []complex128{complex(result, 0)}, nil
	case 1:
		if len(input) < 2 {
			return nil, errors.New("computing: malformed function")
		}

		result := solveFirstDegree(input)
		return []complex128{complex(result, 0)}, nil
	case 2:
		if len(input) < 3 {
			return nil, errors.New("computing: malformed function")
		}

		results := solveSecondDegree(input)
		return results, nil
	default:
		return nil, errors.New("computing: not implemented yet")
	}
}

func solveSecondDegree(chunks []model.ParsingChunk) []complex128 {
	a0 := chunks[0].Coefficient
	a1 := chunks[1].Coefficient
	a2 := chunks[2].Coefficient

	if !util.IsZero(a1) && util.IsZero(a2) {
		firstDegreeChunks := chunks[:2]
		result := solveFirstDegree(firstDegreeChunks)
		return []complex128{complex(result, 0)}
	} else if !util.IsZero(a0) && util.IsZero(a1) && util.IsZero(a2) {
		return []complex128{complex(math.Inf(-1), 0)}
	} else if util.IsZero(a0) && util.IsZero(a1) && util.IsZero(a2) {
		return []complex128{complex(math.Inf(1), 0)}
	} else {
		a := a2
		b := a1
		c := a0

		delta := b*b - 4*a*c

		if util.IsZero(delta) {
			delta = 0
		}

		isComplexNumber := delta < 0
		if isComplexNumber {
			realPart := -b / (2 * a)
			imaginaryPart := sqrt(-delta) / (2 * a)

			x1 := complex(realPart, imaginaryPart)
			x2 := complex(realPart, -imaginaryPart)

			return []complex128{x1, x2}
		}

		xPos := (b*-1 + sqrt(delta)) / (2 * a)
		xNeg := (b*-1 - sqrt(delta)) / (2 * a)

		if xPos == xNeg {
			return []complex128{complex(xPos, 0)}
		}

		return []complex128{complex(xPos, 0), complex(xNeg, 0)}
	}
}

func solveFirstDegree(chunks []model.ParsingChunk) float64 {
	a0 := chunks[0].Coefficient
	a1 := chunks[1].Coefficient

	if !util.IsZero(a0) && util.IsZero(a1) {
		return math.Inf(-1)
	} else if util.IsZero(a0) && util.IsZero(a1) {
		return math.Inf(1)
	} else {
		return -1 * a0 / a1
	}
}

func solveZeroDegree(chunk model.ParsingChunk) float64 {
	if util.IsZero(chunk.Coefficient) {
		return math.Inf(1)
	}

	return math.Inf(-1)
}

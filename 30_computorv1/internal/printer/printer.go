package printer

import (
	"computorv1/internal/model"
	"fmt"
	"math"
	"strings"
)

func Print(input []model.ParsingChunk, errors []model.ValidationError, results []complex128) string {
	reducedFormOutput := buildReducedFormOutput(input)

	totalOutput := reducedFormOutput

	polynomialDegreeOutput, degree := buildPolynomialDegreeOutput(input)
	totalOutput += polynomialDegreeOutput

	if len(errors) > 0 {
		totalOutput += buildErrorOutput(errors)
	} else {
		totalOutput += buildResultOutput(results, degree)
	}

	return totalOutput
}

func buildResultOutput(results []complex128, degree int) string {
	var builder strings.Builder

	for i, result := range results {
		realPart := real(result)
		imaginaryPart := imag(result)

		isNotComplex := imaginaryPart == 0
		if isNotComplex {
			if i == 0 {
				if degree != 2 {
					builder.WriteString("Solution: ")
				} else {
					if len(results) > 1 {
						builder.WriteString("Discriminant is positive and results are: ")
					} else {
						builder.WriteString("Disciminant is zero and result is: ")
					}
				}
			}

			if math.IsInf(realPart, 1) {
				builder.WriteString("any real number.")
			} else if math.IsInf(realPart, -1) {
				builder.WriteString("no solution.")
			} else {
				if i != 0 {
					builder.WriteString(", ")
				}

				fmt.Fprintf(&builder, "%v", realPart)
			}
		} else {
			if i == 0 {
				builder.WriteString("Discrimant is negative and results are: ")
			} else {
				builder.WriteString(", ")
			}

			fmt.Fprintf(&builder, "%v", result)
		}
	}
	builder.WriteString("\n")

	return builder.String()
}

func buildErrorOutput(errors []model.ValidationError) string {
	var builder strings.Builder

	builder.WriteString("Error: ")
	for _, error := range errors {
		switch error {
		case model.ValidationOverDegreeMax:
			builder.WriteString("invalid polynomial degree")
		default:
			builder.WriteString("unknown error")
		}
	}

	builder.WriteString("\n")
	return builder.String()
}

func buildReducedFormOutput(input []model.ParsingChunk) string {
	var builder strings.Builder

	fmt.Fprint(&builder, "Reduced form: ")
	for i, chunk := range input {
		if i > 0 {
			builder.WriteString(" ")
		}

		if chunk.Coefficient < 0 {
			builder.WriteString("- ")
			fmt.Fprintf(&builder, "%g", -chunk.Coefficient)
		} else {
			if i > 0 {
				builder.WriteString("+ ")
			}
			fmt.Fprintf(&builder, "%g", chunk.Coefficient)
		}

		fmt.Fprintf(&builder, " * X^%d", chunk.Exponent)
	}

	builder.WriteString(" = 0\n")

	return builder.String()
}

func buildPolynomialDegreeOutput(input []model.ParsingChunk) (string, int) {
	var builder strings.Builder

	degree := 0
	for _, chunk := range input {
		degree = max(degree, chunk.Exponent)
	}

	if degree == 0 {
		return "", 0
	}

	fmt.Fprintf(&builder, "Polynomial degree: %v\n", degree)
	return builder.String(), degree
}

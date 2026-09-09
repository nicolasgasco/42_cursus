package printer

import (
	"computorv1/internal/model"
	"fmt"
	"strings"
)

func Print(input []model.ParsingChunk) string {
	reducedFormOutput := buildReducedFormOutput(input)
	polynomialDegreeOutput := buildPolynomialDegreeOutput(input)

	totalOutput := reducedFormOutput + polynomialDegreeOutput

	return totalOutput
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

func buildPolynomialDegreeOutput(input []model.ParsingChunk) string {
	var builder strings.Builder

	degree := 0
	for _, chunk := range input {
		degree = max(degree, chunk.Exponent)
	}

	if degree == 0 {
		return ""
	}

	fmt.Fprintf(&builder, "Polynomial degree: %v\n", degree)
	return builder.String()
}

package printer

import (
	"strings"
	"testing"

	"computorv1/internal/model"
)

func TestPrintReducedFormTrimsTrailingZeroTerms(t *testing.T) {
	input := []model.ParsingChunk{
		{Coefficient: 4, Exponent: 0},
		{Coefficient: 2, Exponent: 1},
		{Coefficient: 0, Exponent: 2},
	}

	output := Print(input, nil, nil)

	if !strings.Contains(output, "Reduced form: 4 * X^0 + 2 * X^1 = 0") {
		t.Errorf("Print() = %q, want reduced form without trailing zero terms", output)
	}
}

func TestPrintReducedFormKeepsZeroPolynomial(t *testing.T) {
	input := []model.ParsingChunk{
		{Coefficient: 0, Exponent: 0},
	}

	output := Print(input, nil, nil)

	if !strings.Contains(output, "Reduced form: 0 * X^0 = 0") {
		t.Errorf("Print() = %q, want zero polynomial in reduced form", output)
	}
}

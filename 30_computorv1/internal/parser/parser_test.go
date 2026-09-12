package parser

import (
	"reflect"
	"testing"

	"computorv1/internal/model"
)

func TestParser(t *testing.T) {
	tests := []struct {
		name  string
		input string
		want  []model.ParsingChunk
	}{
		{
			name:  "quadratic equation with right-hand constant",
			input: "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -9.3, Exponent: 2},
				{Coefficient: -1, Exponent: 0},
			},
		},
		{
			name:  "linear equation with right-hand constant",
			input: "5 * X^0 + 4 * X^1 = 4 * X^0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -4, Exponent: 0},
			},
		},
		{
			name:  "degree greater than two",
			input: "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0",
			want: []model.ParsingChunk{
				{Coefficient: 8, Exponent: 0},
				{Coefficient: -6, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: -5.6, Exponent: 3},
				{Coefficient: -3, Exponent: 0},
			},
		},
		{
			name:  "identical constant equations",
			input: "6 * X^0 = 6 * X^0",
			want: []model.ParsingChunk{
				{Coefficient: 6, Exponent: 0},
				{Coefficient: -6, Exponent: 0},
			},
		},
		{
			name:  "different constant equations",
			input: "10 * X^0 = 15 * X^0",
			want: []model.ParsingChunk{
				{Coefficient: 10, Exponent: 0},
				{Coefficient: -15, Exponent: 0},
			},
		},
		{
			name:  "quadratic equation with zero right-hand side",
			input: "1 * X^0 + 2 * X^1 + 5 * X^2 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: 5, Exponent: 2},
			},
		},
		{
			name:  "multiple terms on both sides",
			input: "3 * X^0 + 2 * X^1 = 7 * X^0 - 4 * X^1",
			want: []model.ParsingChunk{
				{Coefficient: 3, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: -7, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
			},
		},
		{
			name:  "quadratic terms on both sides",
			input: "1 * X^0 - 2 * X^1 + 3 * X^2 = 4 * X^0 + 5 * X^1 - 6 * X^2",
			want: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: -2, Exponent: 1},
				{Coefficient: 3, Exponent: 2},
				{Coefficient: -4, Exponent: 0},
				{Coefficient: -5, Exponent: 1},
				{Coefficient: 6, Exponent: 2},
			},
		},
		{
			name:  "several right-hand terms with repeated exponents",
			input: "8 * X^0 = 2 * X^0 + 3 * X^1 - 4 * X^2 + 5 * X^1",
			want: []model.ParsingChunk{
				{Coefficient: 8, Exponent: 0},
				{Coefficient: -2, Exponent: 0},
				{Coefficient: -3, Exponent: 1},
				{Coefficient: 4, Exponent: 2},
				{Coefficient: -5, Exponent: 1},
			},
		},
		{
			name:  "without spaces",
			input: "5*X^0+4*X^1-9.3*X^2=1*X^0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -9.3, Exponent: 2},
				{Coefficient: -1, Exponent: 0},
			},
		},
		{
			name:  "spaces around operators",
			input: "5*X^0 + 4*X^1 - 9.3*X^2 = 1*X^0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -9.3, Exponent: 2},
				{Coefficient: -1, Exponent: 0},
			},
		},
		{
			name:  "spaces around multiplication and exponent",
			input: "5 * X ^ 0 + 4 * X ^ 1 = 2 * X ^ 0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -2, Exponent: 0},
			},
		},
		{
			name:  "cubic terms cancel leaving a linear equation",
			input: "8 * X^0 - 6 * X^1 + 0 * X^2 + 3 * X^3 = 3 * X^3",
			want: []model.ParsingChunk{
				{Coefficient: 8, Exponent: 0},
				{Coefficient: -6, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: 3, Exponent: 3},
				{Coefficient: -3, Exponent: 3},
			},
		},
		{
			name:  "cubic terms cancel leaving a quadratic equation",
			input: "8 * X^0 - 6 * X^1 + 1 * X^2 + 3 * X^3 = 3 * X^3",
			want: []model.ParsingChunk{
				{Coefficient: 8, Exponent: 0},
				{Coefficient: -6, Exponent: 1},
				{Coefficient: 1, Exponent: 2},
				{Coefficient: 3, Exponent: 3},
				{Coefficient: -3, Exponent: 3},
			},
		},
		{
			name:  "zero constant and quadratic coefficients",
			input: "0 * X^0 + 4 * X^1 + 0 * X^2 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
		},
		{
			name:  "all zero quadratic",
			input: "0 * X^0 + 0 * X^1 + 0 * X^2 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
		},
		{
			name:  "all zero cubic",
			input: "0 * X^0 + 0 * X^1 + 0 * X^2 + 0 * X^3 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: 0, Exponent: 3},
			},
		},
		{
			name:  "constant with zero higher-degree terms",
			input: "5 * X^0 + 0 * X^1 + 0 * X^2 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
		},
		{
			name:  "linear with zero quadratic term",
			input: "5 * X^0 + 4 * X^1 + 0 * X^2 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
		},
		{
			name:  "quadratic with zero linear term",
			input: "5 * X^0 + 0 * X^1 + 1 * X^2 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 1, Exponent: 2},
			},
		},
		{
			name:  "terms in descending order",
			input: "0 * X^2 + 4 * X^1 + 5 * X^0 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 2},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: 5, Exponent: 0},
			},
		},
		{
			name:  "unsupported cubic with nonzero coefficient",
			input: "1 * X^0 + 2 * X^1 + 0 * X^2 + 4 * X^3 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: 4, Exponent: 3},
			},
		},
		{
			name:  "multi-digit exponent",
			input: "1 * X^10 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 10},
			},
		},
		{
			name:  "multi-digit exponent with other terms",
			input: "2 * X^123 - 4 * X^10 + 1 * X^0 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 2, Exponent: 123},
				{Coefficient: -4, Exponent: 10},
				{Coefficient: 1, Exponent: 0},
			},
		},
		{
			name:  "sparse quadratic",
			input: "5 * X^0 + 1 * X^2 = 0",
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 1, Exponent: 2},
			},
		},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			got, err := Parser(test.input)
			if err != nil {
				t.Fatalf("Parser(%q) returned an unexpected error: %v", test.input, err)
			}

			if !reflect.DeepEqual(got, test.want) {
				t.Errorf("Parser(%q) = %+v, want %+v", test.input, got, test.want)
			}
		})
	}
}

func TestParserMalformedInput(t *testing.T) {
	tests := []struct {
		name  string
		input string
	}{
		{
			name:  "missing equal sign",
			input: "5 * X^0 + 4 * X^1",
		},
		{
			name:  "invalid coefficient",
			input: "five * X^0 = 0",
		},
		{
			name:  "invalid exponent",
			input: "5 * X^x = 0",
		},
		{
			name:  "multiple equal signs",
			input: "5 * X^0 = 4 * X^0 = 0",
		},
		{
			name:  "missing exponent",
			input: "5 * X^ = 0",
		},
		{
			name:  "missing multiplication",
			input: "5 X^2 = 0",
		},
		{
			name:  "missing variable",
			input: "5 * ^2 = 0",
		},
		{
			name:  "invalid variable",
			input: "5 * Y^2 = 0",
		},
		{
			name:  "extra exponent operator",
			input: "5 * X^2^3 = 0",
		},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			got, err := Parser(test.input)
			if err == nil {
				t.Errorf("Parser(%q) returned chunks %+v, want an error", test.input, got)
			}
		})
	}
}

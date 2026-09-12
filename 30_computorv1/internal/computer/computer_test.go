package computer

import (
	"math"
	"testing"

	"computorv1/internal/model"
)

func TestComputer(t *testing.T) {
	tests := []struct {
		name  string
		input []model.ParsingChunk
		want  []complex128
	}{
		{
			name: "quadratic with complex solutions",
			input: []model.ParsingChunk{
				{Coefficient: 4, Exponent: 0},
				{Coefficient: 3, Exponent: 1},
				{Coefficient: 3, Exponent: 2},
			},
			want: []complex128{
				complex(-0.5, 1.0408329997330663),
				complex(-0.5, -1.0408329997330663),
			},
		},
		{
			name: "quadratic with repeated solution",
			input: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 10, Exponent: 1},
				{Coefficient: 5, Exponent: 2},
			},
			want: []complex128{
				complex(-1, 0),
			},
		},
		{
			name: "quadratic with two real solutions",
			input: []model.ParsingChunk{
				{Coefficient: 4, Exponent: 0},
				{Coefficient: 12, Exponent: 1},
				{Coefficient: 3, Exponent: 2},
			},
			want: []complex128{
				complex(-0.36700683814454793, 0),
				complex(-3.632993161855452, 0),
			},
		},
		{
			name: "linear equation",
			input: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: -7, Exponent: 1},
			},
			want: []complex128{complex(1.0/7.0, 0)},
		},
		{
			name: "any real number",
			input: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
			},
			want: []complex128{complex(math.Inf(1), 0)},
		},
		{
			name: "no solution",
			input: []model.ParsingChunk{
				{Coefficient: -4, Exponent: 0},
			},
			want: []complex128{complex(math.Inf(-1), 0)},
		},
		{
			name: "cubic terms cancel to a linear equation",
			input: []model.ParsingChunk{
				{Coefficient: 8, Exponent: 0},
				{Coefficient: -6, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: 0, Exponent: 3},
			},
			want: []complex128{complex(4.0/3.0, 0)},
		},
		{
			name: "cubic terms cancel to a quadratic equation",
			input: []model.ParsingChunk{
				{Coefficient: 8, Exponent: 0},
				{Coefficient: -6, Exponent: 1},
				{Coefficient: 1, Exponent: 2},
				{Coefficient: 0, Exponent: 3},
			},
			want: []complex128{
				complex(4, 0),
				complex(2, 0),
			},
		},
		{
			name: "all zero quadratic",
			input: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
			want: []complex128{complex(math.Inf(1), 0)},
		},
		{
			name: "constant with zero higher-degree terms",
			input: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
			want: []complex128{complex(math.Inf(-1), 0)},
		},
		{
			name: "linear with zero quadratic term",
			input: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
			want: []complex128{complex(-1.25, 0)},
		},
		{
			name: "quadratic with zero linear term",
			input: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 1, Exponent: 2},
			},
			want: []complex128{
				complex(0, 2.23606797749979),
				complex(0, -2.23606797749979),
			},
		},
		{
			name: "all zero cubic reduced to a constant",
			input: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: 0, Exponent: 3},
			},
			want: []complex128{complex(math.Inf(1), 0)},
		},
		{
			name: "near-zero positive discriminant",
			input: []model.ParsingChunk{
				{Coefficient: 0.9999999999999999, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: 1, Exponent: 2},
			},
			want: []complex128{
				complex(-1, 0),
			},
		},
		{
			name: "near-zero quadratic coefficient reduces to linear",
			input: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: 1e-13, Exponent: 2},
			},
			want: []complex128{
				complex(-1.25, 0),
			},
		},
		{
			name: "near-zero discriminant from decimal coefficients",
			input: []model.ParsingChunk{
				{Coefficient: 1e-13, Exponent: 0},
				{Coefficient: -1e-13, Exponent: 1},
				{Coefficient: 1, Exponent: 2},
			},
			want: []complex128{
				complex(5e-14, 0),
			},
		},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			got, err := Computer(test.input)
			if err != nil {
				t.Fatalf("Computer(%+v) returned an unexpected error: %v", test.input, err)
			}

			if len(got) != len(test.want) {
				t.Fatalf("Computer(%+v) returned %d results, want %d", test.input, len(got), len(test.want))
			}

			for i := range got {
				if math.IsInf(real(got[i]), 0) || math.IsInf(real(test.want[i]), 0) {
					if got[i] != test.want[i] {
						t.Errorf("Computer(%+v) result %d = %v, want %v", test.input, i, got[i], test.want[i])
					}
					continue
				}

				if math.Abs(real(got[i])-real(test.want[i])) > 1e-12 ||
					math.Abs(imag(got[i])-imag(test.want[i])) > 1e-12 {
					t.Errorf("Computer(%+v) result %d = %v, want %v", test.input, i, got[i], test.want[i])
				}
			}
		})
	}
}

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

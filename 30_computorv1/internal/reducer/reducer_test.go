package reducer

import (
	"reflect"
	"testing"

	"computorv1/internal/model"
)

func TestReducer(t *testing.T) {
	tests := []struct {
		name  string
		input []model.ParsingChunk
		want  []model.ParsingChunk
	}{
		{
			name: "quadratic equation with right-hand constant",
			input: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -9.3, Exponent: 2},
				{Coefficient: -1, Exponent: 0},
			},
			want: []model.ParsingChunk{
				{Coefficient: 4, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -9.3, Exponent: 2},
			},
		},
		{
			name: "linear equation with right-hand constant",
			input: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
				{Coefficient: -4, Exponent: 0},
			},
			want: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: 4, Exponent: 1},
			},
		},
		{
			name: "degree greater than two",
			input: []model.ParsingChunk{
				{Coefficient: 8, Exponent: 0},
				{Coefficient: -6, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: -5.6, Exponent: 3},
				{Coefficient: -3, Exponent: 0},
			},
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: -6, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
				{Coefficient: -5.6, Exponent: 3},
			},
		},
		{
			name: "identical constant equations",
			input: []model.ParsingChunk{
				{Coefficient: 6, Exponent: 0},
				{Coefficient: -6, Exponent: 0},
			},
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
			},
		},
		{
			name: "different constant equations",
			input: []model.ParsingChunk{
				{Coefficient: 10, Exponent: 0},
				{Coefficient: -15, Exponent: 0},
			},
			want: []model.ParsingChunk{
				{Coefficient: -5, Exponent: 0},
			},
		},
		{
			name: "quadratic equation with zero right-hand side",
			input: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: 5, Exponent: 2},
			},
			want: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: 5, Exponent: 2},
			},
		},
		{
			name: "unsorted terms",
			input: []model.ParsingChunk{
				{Coefficient: 3, Exponent: 2},
				{Coefficient: 1, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
			},
			want: []model.ParsingChunk{
				{Coefficient: 1, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: 3, Exponent: 2},
			},
		},
		{
			name: "several repeated exponents",
			input: []model.ParsingChunk{
				{Coefficient: 2, Exponent: 0},
				{Coefficient: -5, Exponent: 1},
				{Coefficient: 3, Exponent: 0},
				{Coefficient: 1.5, Exponent: 1},
				{Coefficient: 4, Exponent: 2},
				{Coefficient: -1, Exponent: 2},
			},
			want: []model.ParsingChunk{
				{Coefficient: 5, Exponent: 0},
				{Coefficient: -3.5, Exponent: 1},
				{Coefficient: 3, Exponent: 2},
			},
		},
		{
			name: "terms cancel completely",
			input: []model.ParsingChunk{
				{Coefficient: 7, Exponent: 0},
				{Coefficient: -7, Exponent: 0},
				{Coefficient: 2.5, Exponent: 2},
				{Coefficient: -2.5, Exponent: 2},
			},
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 0, Exponent: 2},
			},
		},
		{
			name: "negative and decimal coefficients",
			input: []model.ParsingChunk{
				{Coefficient: -1.25, Exponent: 0},
				{Coefficient: 3.75, Exponent: 0},
				{Coefficient: -0.5, Exponent: 1},
				{Coefficient: -2.25, Exponent: 1},
			},
			want: []model.ParsingChunk{
				{Coefficient: 2.5, Exponent: 0},
				{Coefficient: -2.75, Exponent: 1},
			},
		},
		{
			name: "sparse exponents",
			input: []model.ParsingChunk{
				{Coefficient: 6, Exponent: 4},
				{Coefficient: 2, Exponent: 0},
				{Coefficient: -3, Exponent: 2},
			},
			want: []model.ParsingChunk{
				{Coefficient: 2, Exponent: 0},
				{Coefficient: -3, Exponent: 2},
				{Coefficient: 6, Exponent: 4},
			},
		},
		{
			name: "zero coefficient between nonzero terms",
			input: []model.ParsingChunk{
				{Coefficient: 3, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: -2, Exponent: 2},
			},
			want: []model.ParsingChunk{
				{Coefficient: 3, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: -2, Exponent: 2},
			},
		},
		{
			name: "only zero coefficients",
			input: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 0, Exponent: 1},
				{Coefficient: 0, Exponent: 2},
			},
		},
		{
			name: "zero coefficient with repeated exponent",
			input: []model.ParsingChunk{
				{Coefficient: 4, Exponent: 0},
				{Coefficient: 0, Exponent: 0},
				{Coefficient: -4, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
				{Coefficient: 0, Exponent: 1},
			},
			want: []model.ParsingChunk{
				{Coefficient: 0, Exponent: 0},
				{Coefficient: 2, Exponent: 1},
			},
		},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			got, err := Reducer(test.input)
			if err != nil {
				t.Fatalf("Reducer() returned an unexpected error: %v", err)
			}

			if !reflect.DeepEqual(got, test.want) {
				t.Errorf("Reducer(%+v) = %+v, want %+v", test.input, got, test.want)
			}
		})
	}
}

func TestReducerEmptyInput(t *testing.T) {
	got, err := Reducer(nil)
	if err != nil {
		t.Fatalf("Reducer(nil) returned an unexpected error: %v", err)
	}

	if len(got) != 0 {
		t.Fatalf("Reducer(nil) returned %+v, want an empty result", got)
	}
}

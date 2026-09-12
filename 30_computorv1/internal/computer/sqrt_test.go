package computer

import (
	"math"
	"testing"
)

func TestSqrt(t *testing.T) {
	tests := []struct {
		name  string
		input float64
	}{
		{name: "zero", input: 0},
		{name: "one", input: 1},
		{name: "perfect square", input: 4},
		{name: "larger perfect square", input: 25},
		{name: "irrational result", input: 2},
		{name: "fraction", input: 0.25},
		{name: "small fraction", input: 0.04},
		{name: "decimal fraction", input: 0.1},
		{name: "decimal fraction near one", input: 0.81},
		{name: "decimal value", input: 3.14},
		{name: "decimal value greater than ten", input: 10.5},
		{name: "decimal value with multiple digits", input: 123.456},
		{name: "very small value", input: 1e-20},
		{name: "large value", input: 1e12},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			got := sqrt(test.input)
			want := math.Sqrt(test.input)
			if math.Abs(got-want) > 1e-12 {
				t.Errorf("sqrt(%g) = %g, want %g", test.input, got, want)
			}
		})
	}
}

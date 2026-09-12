package util

const Epsilon = 1e-12

func Abs(value float64) float64 {
	if value < 0 {
		return -value
	}
	return value
}

func IsZero(value float64) bool {
	return Abs(value) < Epsilon
}

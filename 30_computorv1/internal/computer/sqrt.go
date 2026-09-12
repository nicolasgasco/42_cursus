package computer

func sqrt(value float64) float64 {
	if value < 0 {
		panic("sqrt: negative number")
	}
	if value == 0 {
		return 0
	}

	guess := 1.0
	if value > 1 {
		guess = value
	}

	for i := 0; i < 100; i++ {
		next := (guess + value/guess) / 2

		if abs(next-guess) < 1e-12 {
			return next
		}

		guess = next
	}

	return guess
}

func abs(value float64) float64 {
	if value < 0 {
		return -value
	}
	return value
}

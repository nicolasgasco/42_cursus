package model

type ParsingChunk struct {
	Coefficient float64
	Exponent    int
}

type ValidationError string

const (
	ValidationOverDegreeMax ValidationError = "validation.over_degree_max"
)

package parser

type Sign rune

const (
	Positive Sign = '+'
	Negative Sign = '-'
)

type ParsingChunk struct {
	coefficient float64
	exponent    int
}

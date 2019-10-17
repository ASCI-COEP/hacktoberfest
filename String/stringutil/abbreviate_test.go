package stringutil

import "testing"

func TestAbbreviate(t *testing.T) {
	samples := []struct {
		input, output string
	}{
		{"World Health Organization", "WHO"},
		{"Top, of The World", "TOTW"},
		{"Natural Language processing", "NLP"},
	}
	for _, sample := range samples {
		op := Abbreviate(sample.input)
		if op != sample.output {
			t.Errorf("Abbreviate(%q) should equal %q but got %q", sample.input, sample.output, op)
		}
	}
}

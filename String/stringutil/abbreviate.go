package stringutil

import "strings"

func Abbreviate(sentence string) string {
	words := strings.Split(sentence, " ")
	acronym := ""

	for _, word := range words {
		acronym += strings.Title(string([]rune(word)[0]))
	}

	return acronym
}

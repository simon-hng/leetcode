package main

func addSpaces(s string, spaces []int) string {
	result := make([]byte, len(s)+len(spaces))

	j := 0
	for i := range s {
		if j < len(spaces) && i == spaces[j] {
			result[i+j] = ' '
			j++
		}
		result[i+j] = s[i]
	}

	return string(result)
}

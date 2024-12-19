package main

import (
	"testing"
)

var testData = [][]byte{
	[]byte("MMMSXXMASM"),
	[]byte("MSAMXMSMSA"),
	[]byte("AMXSXMAAMM"),
	[]byte("MSAMASMSMX"),
	[]byte("XMASAMXAMM"),
	[]byte("XXAMMXXAMA"),
	[]byte("SMSMSASXSS"),
	[]byte("SAXAMASAAA"),
	[]byte("MAMMMXMMMM"),
	[]byte("MXMXAXMASX"),
}

func TestExample(t *testing.T) {
	actual := part1(testData)

	if actual != 18 {
		t.Errorf("Expected 18, but got %d", actual)
	}
}

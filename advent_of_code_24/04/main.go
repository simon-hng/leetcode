package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("./input.txt")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	var data [][]byte

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Bytes()
		data = append(data, line)
	}

	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading file:", err)
		return
	}

	fmt.Println("Part 1:", part1(data))
	fmt.Println("Part 2:", part2(data))
}

type Coords struct {
	row int
	col int
}

func check(data [][]byte, row int, col int) int {
	if row+3 > len(data) || col+3 >= len(data[0]) {
		return 0
	}

	orientations := [8][4]Coords{
		{{0, 0}, {1, 1}, {2, 2}, {3, 3}},
		{{3, 0}, {2, 1}, {1, 2}, {0, 3}},
		{{3, 3}, {2, 2}, {1, 1}, {0, 0}},
		{{0, 3}, {1, 2}, {2, 1}, {3, 0}},

		{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
		{{0, 3}, {0, 2}, {0, 1}, {0, 0}},
		{{3, 0}, {2, 0}, {1, 0}, {0, 0}},
	}

	countFound := 0

	for _, orientation := range orientations {
		match := true
		for i, coord := range orientation {
			if data[row+coord.row][col+coord.col] != "XMAS"[i] {
				match = false
				break
			}
		}
		if match {
			countFound += 1
		}
	}

	return countFound
}

func part1(data [][]byte) int {
	result := 0
	for i := 0; i <= len(data)-4; i++ {
		for j := 0; j <= len(data[i])-4; j++ {
			result += check(data[i:i+4], i, j)
		}
	}
	return result
}

func part2(data [][]byte) int {
	// Implement part 2 logic here
	return 0
}

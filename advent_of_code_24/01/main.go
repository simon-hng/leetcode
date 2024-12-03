package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	data, err := os.ReadFile("./01.txt")
	if err != nil {
		fmt.Println("Error reading file:", err)
		return
	}

	lines := strings.Split(string(data), "\n")

	var leftList []int
	var rightList []int
	for _, line := range lines {
		fields := strings.Fields(line)
		if len(fields) == 2 {
			leftValue, _ := strconv.Atoi(fields[0])
			leftList = append(leftList, leftValue)

			rightValue, _ := strconv.Atoi(fields[1])
			rightList = append(rightList, rightValue)
		}
	}

	// Part 1
	sort.Ints(leftList)
	sort.Ints(rightList)

	result1 := 0

	for i := 0; i < len(leftList); i++ {
		diff := leftList[i] - rightList[i]
		if diff < 0 {
			result1 -= diff
		} else {
			result1 += diff
		}
	}

	fmt.Println("Part 1:", result1)

	// Part 2
	var getCount = func(left int) int {
		count := 0
		for _, right := range rightList {
			if right == left {
				count++
			}
		}

		return count
	}

	result2 := 0
	leftToCount := make(map[int]int)
	for _, left := range leftList {
		if _, ok := leftToCount[left]; !ok {
			leftToCount[left] = getCount(left)
		}

		result2 += left * leftToCount[left]
	}

	fmt.Println("Part 2:", result2)
}

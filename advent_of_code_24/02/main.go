package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func test(report []int) bool {
	if len(report) < 2 {
		return true
	}

	isDecreasing := report[0] > report[1]
	for i := 1; i < len(report); i++ {
		prev := report[i-1]
		current := report[i]

		if isDecreasing && prev <= current {
			return false
		} else if !isDecreasing && prev >= current {
			return false
		}

		dist := abs(current - prev)
		if dist < 1 || dist > 3 {
			return false
		}
	}
	return true
}

func first_part(reports [][]int) int {
	result := 0
	for _, report := range reports {
		if test(report) {
			result++
		}
	}
	return result
}
func remove(slice []int, s int) []int {
	return append(slice[:s], slice[s+1:]...)
}

func second_part(reports [][]int) int {
	result := 0

	for _, report := range reports {
		safeWithRemoval := false
		for i := 0; i < len(report); i++ {
			modifiedReport := make([]int, len(report)-1)
			copy(modifiedReport, report[:i])
			copy(modifiedReport[i:], report[i+1:])

			if test(modifiedReport) {
				safeWithRemoval = true
			}
		}
		if safeWithRemoval {
			result++
		}
	}

	return result
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	data, err := os.ReadFile("./input.txt")
	if err != nil {
		panic(err)
	}

	var parseReports = func(reports []string) [][]int {
		result := [][]int{}
		for _, reportStr := range reports {
			if reportStr == "" {
				continue
			}
			tokens := strings.Split(reportStr, " ")

			var report []int
			for _, token := range tokens {
				num, err := strconv.Atoi(token)
				if err != nil {
					fmt.Println("Error converting string to int:", err)
					continue
				}
				report = append(report, num)
			}
			result = append(result, report)
		}

		return result
	}

	reports := parseReports(strings.Split(string(data), "\n"))

	first_result := first_part(reports)
	fmt.Println("First result:", first_result)

	second_result := second_part(reports)
	fmt.Println("Second result:", second_result)
}

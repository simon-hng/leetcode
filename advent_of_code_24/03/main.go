package main

import (
	"fmt"
	"os"
	"regexp"
	"strconv"
)

type OperationType int

const (
	Multiplication OperationType = iota
	Do
	Dont
)

type Operation struct {
	op_type OperationType
	first   int
	second  int
}

func first_part(ops []Operation) int {
	result := 0
	for _, op := range ops {
		if op.op_type == Multiplication {
			result += op.first * op.second
		}
	}
	return result
}

func second_part(ops []Operation) int {
	result := 0
	enabled := true

	for _, op := range ops {
		switch op.op_type {
		case Do:
			enabled = true
		case Dont:
			enabled = false
		case Multiplication:

			if enabled {
				result += op.first * op.second
			}
		}
	}

	return result
}

func main() {
	data, err := os.ReadFile("./input.txt")
	if err != nil {
		panic(err)
	}

	// Regex pattern for matching operations
	pattern := `mul\((\d+),(\d+)\)|do\(\)|don\'t\(\)`
	re := regexp.MustCompile(pattern)

	ops := []Operation{}

	for _, match := range re.FindAllStringSubmatch(string(data), -1) {
		switch {
		case match[0][:3] == "mul":
			first, _ := strconv.Atoi(match[1])
			second, _ := strconv.Atoi(match[2])
			ops = append(ops, Operation{
				op_type: Multiplication,
				first:   first,
				second:  second,
			})
		case match[0] == "do()":
			ops = append(ops, Operation{
				op_type: Do,
			})
		case match[0] == "don't()":
			ops = append(ops, Operation{
				op_type: Dont,
			})
		}
	}
	first_result := first_part(ops)
	fmt.Println("First result:", first_result)

	second_result := second_part(ops)
	fmt.Println("Second result:", second_result)
}

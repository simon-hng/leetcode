package main

import (
	"fmt"
	"testing"
)

var testData = [][]int{
	{7, 6, 4, 2, 1},
	{1, 2, 7, 8, 9},
	{9, 7, 6, 2, 1},
	{1, 3, 2, 4, 5},
	{8, 6, 4, 4, 1},
	{1, 3, 6, 7, 9}}

func TestReportSafe(t *testing.T) {
	if !test(testData[0]) {
		t.Error(testData[0], "should be safe")
	}

	if !test(testData[5]) {
		t.Error(testData[5], "should be safe")
	}
}

func TestDecreaseTooBig(t *testing.T) {
	if test(testData[1]) {
		t.Error(testData[1], "should be unsafe")
	}
	if test(testData[2]) {
		t.Error(testData[2], "should be unsafe")
	}
}

func TestZigzagDecrese(t *testing.T) {
	if test(testData[3]) {
		t.Error(testData[3], "should be unsafe")
	}
	if test(testData[4]) {
		t.Error(testData[4], "should be unsafe")
	}
}

func TestPartTwo(t *testing.T) {
	fmt.Println(testData)
	if actual := second_part(testData); actual != 4 {
		t.Error("Expected 4, got", actual)
	}
}

func TestWithoutRemoval(t *testing.T) {
	input := [][]int{
		testData[0],
	}

	if actual := second_part(input); actual != 1 {
		t.Error("Should be safe without removal, got", actual)
	}
}

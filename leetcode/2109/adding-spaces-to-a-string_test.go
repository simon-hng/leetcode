package main

import "testing"

func TestAddSpaces(t *testing.T) {
	tests := []struct {
		s      string
		spaces []int
		want   string
	}{
		{"LeetcodeHelpsMeLearn", []int{8, 13, 15}, "Leetcode Helps Me Learn"},
	}
	for _, tt := range tests {
		t.Run(tt.s, func(t *testing.T) {
			if got := addSpaces(tt.s, tt.spaces); got != tt.want {
				t.Errorf("addSpaces() = %v, want %v", got, tt.want)
			}
		})
	}
}

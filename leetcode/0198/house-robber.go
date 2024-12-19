//go:build ignore

package main

func houseVisit(i int, nums []int, cache map[int]int) int {
	if i >= len(nums) {
		return 0
	}

	if val, hit := cache[i]; hit {
		return val
	}

	with_rob := nums[i] + houseVisit(i+2, nums, cache)
	without_rob := houseVisit(i+1, nums, cache)

	cache[i] = max(with_rob, without_rob)
	return cache[i]
}

func rob(nums []int) int {
	cache := make(map[int]int)
	return houseVisit(0, nums, cache)
}

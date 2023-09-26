package main

func twoSum(nums []int, target int) []int {
	var valToIndex = make(map[int]int)

	for i := 0; i < len(nums); i++ {
		if value, mapContains := valToIndex[target-nums[i]]; mapContains {
			return []int{value, i}
		}
		valToIndex[nums[i]] = i
	}

	return []int{}
}

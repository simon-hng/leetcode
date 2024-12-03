//go:build ignore

package main

func checkIfExist(arr []int) bool {
	values := make(map[int]struct{})

	for _, v := range arr {
		if _, ok := values[v*2]; ok {
			return true
		}

		if _, ok := values[v/2]; ok && v%2 == 0 {
			return true
		}

		values[v] = struct{}{}
	}

	return false
}

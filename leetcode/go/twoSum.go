package main

func twoSum(nums []int, target int) []int {
	res := map[int]int{}
	for index, val := range nums {
		res[val] = index
	}
	for index, v := range nums {
		if _, ok := res[target-v]; ok && index != res[target-v] {
			return []int{index, res[target-v]}
		}
	}
	return nil
}

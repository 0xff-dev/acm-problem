package main

import "fmt"

func twoSumII(numbers []int, target int) []int {
	i, j := 0, len(numbers)-1
	for i < j {
		tmp := numbers[i] + numbers[j]
		if tmp == target {
			return []int{i + 1, j + 1}
		} else if tmp > target {
			j--
		} else {
			i++
		}
	}
	return nil
}
func main() {
	fmt.Println(twoSumII([]int{2, 7, 11, 15}, 9))
}

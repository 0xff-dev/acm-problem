package main

import (
	"fmt"
	"interview/solve"
)

func main() {
	solve.FindCommonNum([]int{1, 2, 3, 4, 5}, []int{2, 3, 4, 5, 6})
	solve.FindCommonNum([]int{1, 3, 5, 7, 9}, []int{2, 4, 6, 9})
	solve.FindCommonNum([]int{0, 2, 3}, []int{1})
	solve.FindCommonNum([]int{2, 3, 4}, []int{})
	fmt.Println(solve.Judge("4579K", "AAAA2"))
	// 时间紧迫, 没有过多的测试, 见谅
}

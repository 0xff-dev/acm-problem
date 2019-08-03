/*
	题目描述:
	有一个数轴。长度为L， 0，1，2，3...L, 每个点的位置一棵树， 现在给定一系列的区间，区间的树被砍，
	区间可能有重复的地方，求砍完树还有多少树剩余
*/
package main

import (
	"fmt"
	"sort"
)

type SortArray [][2]int

func (sa SortArray) Len() int {
	return len(sa)
}

func (sa SortArray) Less(i, j int) bool {
	if sa[i][0] == sa[j][0] {
		return sa[i][1] < sa[j][1]
	}
	return sa[i][0] < sa[j][0]
}

func (sa SortArray) Swap(i, j int) {
	sa[i], sa[j] = sa[j], sa[i]
}

func main() {
	data := [][2]int{
		{1, 4}, {2, 6}, {1, 2}, {8, 9},
	}
	sort.Sort(SortArray(data))
	now := data[0]
	trees := data[0][1] - data[0][0] + 1
	for _, item := range data[1:] {
		if item[0] > now[1] {
			trees += item[1] - item[0] + 1
            now = item
		} else if item[1] > now[1] {
			trees += item[1] - now[1]
            now[1] = item[1]
		}
	}
	fmt.Println(trees)
}

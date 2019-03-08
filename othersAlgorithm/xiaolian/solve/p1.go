package main

import "fmt"

func FindCommonNum(nums1, nums2 []int) {
	// 空的情况不需要给出结果
	if len(nums1) == 0 || len(nums2) == 0 {
		fmt.Println("list is empty, return")
		return
	}
	flag := false
	index1, index2 := 0, 0
	length1, length2 := len(nums1), len(nums2)
	for index1 < length1 && index2 < length2 {
		if nums1[index1] == nums2[index2] {
			flag = true
			fmt.Print(nums1[index1], " ")
			index1++
			index2++
		} else if nums1[index1] > nums2[index2] {
			index2++
		} else {
			index1++
		}
	}
	if !flag {
		fmt.Print("Not found")
	}
	fmt.Println()
}

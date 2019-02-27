package main

import "math"

func sum(a, b float64) float64 {
	return float64((a + b) / 2)
}
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n1l, n2l := len(nums1), len(nums2)
	mid := (n1l + n2l) / 2
	var flag bool = false
	if mid%2 == 0 {
		mid -= 1
		flag := true
	}
	i, j := 0, 0
	index := 0
	for i < n1l && j < n2l {
		if index == mid {
			if !flag {
				return math.Min(float64(nums1[i]), float64(nums2[j]))
			} else {
				if nums1[i] < nums2[j] {
					if i == n1l-1 {
						return sum(float64(nums1[i]), float64(nums2[j]))
					} else {
						return sum(float64(nums1[i]), math.Min(float64(nums1[i+1]), float64(nums2[j])))
					}
				} else {
					if j == n2l-1 {
						return sum(float64(nums1[i]), float64(nums2[j]))
					} else {
						return sum(float64(nums2[j]), math.Min(float64(nums2[j+1]), float64(nums1[i])))
					}
				}
			}
		}
		index++
		if nums1[i] < nums2[j] {
			i++
		} else {
			j++
		}
	}
	if i < n1l {
		if index == mid {
			if flag {
				return sum(float64(nums1[i]), float64(nums1[i+1]))
			} else {
				return float64(nums1[i])
			}
		}
		index++
		i++
	}
	if j < n2l {
		if index == mid {
			if flag {
				return sum(float64(nums2[j]), float64(nums2[j+1]))
			} else {
				return float64(nums2[j])
			}
		}
		index++
		j++
	}
	return float64(0)
}

package solve

import "fmt"
import "sort"

var maps = map[string]int{
	"T": 10,
	"J": 10,
	"Q": 10,
	"K": 10,
	"A": 1,
	"2": 2,
	"3": 3,
	"4": 4,
	"5": 5,
	"6": 6,
	"7": 7,
	"8": 8,
	"9": 9,
}

type Arr [2]int // 用来存储不用于`牛`计算的index

func Judge(str1, str2 string) int {
	// 1 str1大, -1 str2大, 0 相等
	nums1 := strToNumList(str1)
	nums2 := strToNumList(str2)
	// 开始二者都没有牛
	cattle1, cattle2 := false, false
	indexs1 := hasCattle(nums1, &cattle1)
	indexs2 := hasCattle(nums2, &cattle2)
	if !cattle1 && !cattle1 {
		// 寻找二者最大的
		return NocattleCompare(nums1, nums2)
	} else if cattle1 && !cattle2 {
		return 1
	} else if !cattle1 && cattle2 {
		return -1
	} else {
		// 二者都有牛, 取判断里面的细节
		// 因为存在多个情况, 所以, 我呢
		return Compare(indexs1, indexs2, nums1, nums2)
	}
}

func NocattleCompare(nums1, nums2 []int) int {
	// 两个人都没有牛, 找最大的比较
	flag1 := sort.Search(len(nums1), func(i int) bool { return nums1[i] == 1 })
	flag2 := sort.Search(len(nums1), func(i int) bool { return nums2[i] == 1 })
	if flag1 == 5 && flag2 == 5 {
		sort.Ints(nums1)
		sort.Ints(nums2)
		for i := 4; i >= 0; i-- {
			if nums1[i] > nums2[i] {
				return 1
			} else if nums1[i] < nums2[i] {
				return -1
			}
		}
		return 0
	} else if flag1 == 5 && flag2 != 5 {
		return -1
	}
	return 1
}

func Compare(indexs1, indexs2 []Arr, nums1, nums2 []int) int {
	// 都会用最大的去比较, 所以, 对每个indexs, 进行一个比较拿到最大的那个去比较
	maxCattle1 := -1
	maxCattle2 := -1
	flag1, flag2 := false, false // 是否有A
	for _, arr := range indexs1 {
		tmp := (nums1[arr[0]] + nums1[arr[1]]) % 10
		if tmp == 0 {
			maxCattle1 = 0
			flag1 = true
			break
		}
		if tmp > maxCattle1 {
			maxCattle1 = tmp
		}
	}
	for _, arr := range indexs2 {
		tmp := (nums2[arr[0]] + nums2[arr[1]]) % 10
		if tmp == 0 {
			maxCattle2 = 0
			flag2 = true
			break
		}
		if tmp > maxCattle1 {
			maxCattle1 = tmp
		}
	}
	// 没有一个出现妞妞的情况
	if !flag1 && !flag2 {
		if maxCattle1 > maxCattle2 {
			return 1
		} else if maxCattle1 < maxCattle2 {
			return -1
		} else {
			return 0
		}
	} else if flag1 && flag2 {
		// 都出现牛牛的情况
		return 0
	} else if flag1 && !flag2 {
		// 第一个出现
		return 1
	} else {
		// 第二个出现
		return -1
	}
}

func strToNumList(str string) []int {
	// 将字符串变成数字数组
	res := make([]int, 0)
	for _, s := range str {
		res = append(res, maps[fmt.Sprintf("%c", s)])
	}
	return res
}

func returmDoubleNum(ints [3]int) Arr {
	// 计算用于牛剩下的两个数字
	auxArray := make([]int, 5)
	arr := Arr{}
	for _, i := range ints {
		auxArray[i] = 1
	}
	index := 0
	for _, i := range auxArray {
		if i == 0 {
			arr[index] = i
			index++
		}
	}
	return arr
}
func hasCattle(nums []int, cattle *bool) []Arr {
	// 考虑到使用原来的下标, 同时数据较少, 就不排序, 放弃使用1停2动的算法, 直接for三层
	// 返回值值一个二维数组, 每个都是找到牛的剩余两个数字, 方便后面的计算
	res := make([]Arr, 0)
	for i := 0; i < 3; i++ {
		for j := i + 1; j < 4; j++ {
			for k := j + 1; k < 5; k++ {
				tmp := nums[i] + nums[j] + nums[k]
				if tmp == 10 || tmp == 20 || tmp == 30 {
					*cattle = true
					res = append(res, returmDoubleNum([3]int{i, j, k}))
				}
			}
		}
	}
	return res
}

# 排序算法

from random import shuffle


def quick_sort(nums: tuple, l, r):
    if l<r:
        aim = nums[l]
        i, j = l, r
        while i<j:
            while i<j and nums[j]>aim:
                j -= 1
            while i<j and nums[i]<aim:
                i += 1
            if i<j:
                nums[i], nums[j] = nums[j], nums[i]
        quick_sort(nums, l, i-1)
        quick_sort(nums, i+1, r)

res = [i for i in range(20)]
shuffle(res)
quick_sort(res, 0, len(res)-1)
print(res)
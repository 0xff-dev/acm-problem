class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def binary_search(numbers: list, target):
            left, right = 0, len(numbers)-1
            while left<=right:
                mid = (left+right) // 2
                if numbers[mid] == target:
                    return mid
                elif numbers[mid]>target:
                    right = mid-1
                else:
                    left = mid+1
            return -1
        index = binary_search(nums, target)
        if index == -1:
            return [-1, -1]
        else:
            print(index)
            left, right = index, index
            while left>=0 and nums[left] == target:
                left -= 1
            while right<len(nums) and nums[right] == target:
                right += 1
            return [left+1, right-1]

obj = Solution()
print(obj.searchRange([5, 7, 7, 8, 8, 10], 8))
print(obj.searchRange([5,7,7,8,8,10], 6))
print(obj.searchRange([1,1,1,1], 1))
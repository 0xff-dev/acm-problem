class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        for index, value in enumerate(nums):
            if target <= value:
                return index
        return len(nums)

obj  = Solution()
print(obj.searchInsert([1,2,3,4], 0))
print(obj.searchInsert([1,2,3,4], 8))
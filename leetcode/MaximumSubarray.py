class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 0
        while index<len(nums):
            if nums[index]>=0:
                break
            index += 1
        if index == len(nums):
            return min(nums)
        result = 0
        max_res = -100000
        for i in nums:
            result += i
            if result >= 0:
                max_res = max(result, max_res)
            else:
                result = 0
        return max_res


obj = Solution()
print(obj.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
print(obj.maxSubArray([-1]))
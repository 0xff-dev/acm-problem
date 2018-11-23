#!/usr/bin/env python
# coding=utf-8
class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        import json
        res = []
        length = len(nums)
        def generatr(nums, start):
            if start == length-1:
                if nums not in res:
                    res.append(json.loads(json.dumps(nums)))
                return
            else:
                for i in range(start, length):
                    nums[start], nums[i] = nums[i], nums[start]
                    generatr(nums, start+1)
                    nums[i], nums[start] = nums[start], nums[i]
        generatr(nums, 0)
        return res


obj = Solution()
print(obj.permuteUnique([1,1,2]))

class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(nums) < 4:
            return []
        res = set()
        nums.sort()
        for out_index in range(len(nums)-3):
            for in_index in range(out_index+1, len(nums)-2):
                start, end = in_index+1, len(nums)-1
                while start<end:
                    tmp_sum = nums[out_index] + nums[in_index] + nums[start]+ \
                              nums[end]
                    if tmp_sum > target:
                        end -= 1
                    elif tmp_sum < target:
                        start += 1
                
                    elif tmp_sum == target:
                        # [-3, -2, -1, 0, 0, 1, 2, 3]会出现重复的答案
                        res.add(tuple([nums[out_index], nums[in_index], nums[start], nums[end]]))
                        while start<end and nums[start] == nums[start+1]:
                            start += 1
                        while start<end and nums[end] == nums[end-1]:
                            end -= 1
                        start += 1
                        end -= 1
        return [list(index) for index in res]
print(Solution().fourSum([-3, -2, -1, 0, 0, 1, 2, 3], 0))
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        import json
        res = []
        length = len(nums)
        def generate(nums, start):
            if start == len(nums)-1:
                res.append(json.loads(json.dumps(nums)))
                return
            else:
                for i in range(start, len(nums)):
                    nums[start], nums[i] = nums[i], nums[start]
                    generate(nums, start+1)
                    nums[i], nums[start] = nums[start], nums[i]
        generate(nums, 0)
        return res


obj = Solution()
print(obj.permute([1, 2, 3]))
print(obj.permute([2, 3, 4, 5]))
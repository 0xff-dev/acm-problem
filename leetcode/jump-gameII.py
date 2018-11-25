class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lenth = len(nums)
        if lenth == 0:
            return 0
        res, index = 1, 1
        can_reach, next_can_reach = nums[0], 0
        while index<=can_reach and index<lenth-1:
            # 这里用index+nums[index]来表达最远可以到达的距离
            next_can_reach = max(next_can_reach, nums[index]+index)
            if index == can_reach:
                res += 1
                can_reach = next_can_reach
            index += 1
        if index<lenth-1:
            return -1
        return res

obj = Solution()
print(obj.jump([2,3,1,1,4]))
print(obj.jump([2,0,1,1,4]))
print(obj.jump([2,3,3,3,4]))
print(obj.jump([4,1,1,3,1,1]))
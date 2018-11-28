class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        if length == 0:
            return False
        if length == 1:
            return True
        index = 1
        can_arrive = nums[0]
        next_arrive = 0
        while index<=can_arrive and index<length-1:
            next_arrive = max(next_arrive, nums[index]+index)
            if index == can_arrive:
                can_arrive = next_arrive
            index += 1
        if can_arrive>=length-1:
            return True
        return False

print(Solution().canJump([3,2,1,0,4]))
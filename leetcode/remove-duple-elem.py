class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 0
        length = len(nums)
        while index<length-1:
            while index<length-1 and nums[index] == nums[index+1]:
                del nums[index+1]
                length -= 1
            index += 1
        return length

nums = [0,0,1,1,1,2,2,3,3,4]
obj = Solution()
print(obj.removeDuplicates(nums))
print(nums)
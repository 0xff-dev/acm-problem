class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = [0 for i in range(len(nums))]
        length = len(nums)
        for index, value in enumerate(nums):
            if value == 0:
                continue
            for i in range(value+1):
                if index+i < length:
                    if i == 0:
                        continue
                    if res[index+i] == 0:
                        res[index+i] = res[index]+1
                    else:
                        res[index+i] = min(res[index]+1, res[index+i])
        return res[-1]
    

obj = Solution()
print(obj.jump([2,3,1,1,4]))
print(obj.jump([2,0,1,1,4]))
print(obj.jump([2,3,3,3,4]))
print(obj.jump([4,1,1,3,1,1]))
class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 1:
            return -1 if nums[0] != target else 0
            
        def binary_dearch(numbers, target):
            left, right = 0, len(numbers)-1
            while left<=right:
                mid = int((left+right)/2)
                if numbers[mid] == target:
                    return mid
                elif numbers[mid]>target:
                    right = mid-1
                else:
                    left = mid+1
            return -1
        
        def binary_dearch_location(numbers):
            i, length = 0, len(numbers)
            while i<length-1:
                if numbers[i]>numbers[i+1]:
                    return i
                i += 1
        index = binary_dearch_location(nums)
        if index is None:
            return binary_dearch(nums, target)
        res = binary_dearch(nums[0:index+1], target)
        if res != -1:
            return res
        else:
            res = binary_dearch(nums[index+1:], target)
            if res == -1:
                return -1
            else:
                return index+1+res

obj = Solution()
print(obj.search([4, 5, 6, 7, 0, 1, 2], 0))
print(obj.search([4, 5, 6, 7, 0, 1, 2], 3))
print(obj.search([1, 3], 0))
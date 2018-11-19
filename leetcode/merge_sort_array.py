class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        pre_index = 0
        for v in nums2[:n]:
            index = pre_index
            length, end_index = m, m
            while index < length and nums1[index]<= v:
                index += 1
            while end_index>index:
                nums1[end_index] = nums1[end_index-1]
                end_index -= 1
            nums1[index] = v
            pre_index = index
            m += 1
obj = Solution()
print(obj.merge([1,2,3,0,0,0], 3, [2,5,6], 3))
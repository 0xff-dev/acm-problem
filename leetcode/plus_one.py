class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        cf = 0
        for i in range(len(digits)-1,-1,-1):
            if i == len(digits) -1:
                mmp = digits[i]+1+cf
            else:
                mmp = digits[i]+cf
            if mmp >= 10:
                digits[i] = mmp % 10
                cf = mmp//10
            else:
                digits[i] = mmp
                cf = 0
                break
        if cf:
            digits.insert(0, cf)
        return digits


obj = Solution()
print(obj.plusOne([1,2,3]))
print(obj.plusOne([1,2,3,9]))
print(obj.plusOne([3,5,6]))
print(obj.plusOne([0,0,0]))
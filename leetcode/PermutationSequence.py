class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        _str = [str(i) for i in range(1, n+1)]
        res = 1
        digits = [i for i in range(1, n+1)]
        fac = []
        for i in range(1, n+1):
            fac.append(res*i)
            res *= i
        res = ''
        while digits:
            n -= 1
            num = digits[(k-1)//fac[n-1]]
            res += str(num)
            digits.remove(num)
            k %= fac[n-1]
        return res

obj = Solution()
print(obj.getPermutation(1,1))
print(obj.getPermutation(3,3))
print(obj.getPermutation(3,5))
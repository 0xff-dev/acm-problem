class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def func(pat='', left=n, right=n, res=[]):
            if left>0:
                func(pat+'(', left-1, right, res)
            if right>left:
                func(pat+')', left, right-1)
            if right == 0:
                res.append(pat)
            return res
        return func('', n, n)

o = Solution()
print(o.generateParenthesis(3))
print(o.generateParenthesis(1))
print(o.generateParenthesis(4))
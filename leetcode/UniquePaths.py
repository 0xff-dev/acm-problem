class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        """
        自己考虑的是搜索, 还是差火候, 导致搜索的有点过分了....直接挂掉
        """
        direction = [(0, 1), (1, 0)]
        ans = 0
        def auxi_func(x, y):
            if x == n-1 and y == m-1:
                nonlocal ans
                ans += 1
                return
            for _dir in direction:
                if x+_dir[0]<=n-1 and y+_dir[1]<=m-1:
                    auxi_func(x+_dir[0], y+_dir[1])
        auxi_func(0, 0)
        return ans
s = Solution()
print(s.uniquePaths(3, 2))
print(s.uniquePaths(7, 3))
print(s.uniquePaths(23, 12))

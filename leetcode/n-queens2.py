#!/usr/bin/env python
# coding=utf-8
class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        array = [0 for i in range(n)]
        def get_res(row):
            if row == n:
                nonlocal res
                res += 1
            else:
                for i in range(n):
                    flag = True
                    array[row] = i
                    for j in range(row):
                        if array[j]==array[row] or row-array[row]==j-array[j] or row+array[row]==j+array[j]:
                            flag = False
                            break
                    if flag:
                        get_res(row+1)
        get_res(0)
        return res

obj = Solution()
print(obj.totalNQueens(4))
print(obj.totalNQueens(8))

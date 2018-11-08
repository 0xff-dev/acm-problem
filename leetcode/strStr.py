#!/usr/bin/env python
# coding=utf-8

class Solution:

    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == '':
            return 0
        # exec kmp
        h_len = len(haystack)
        n_len = len(needle)
        def get_next(_str):
            _str_len = len(_str)
            next_arr = [-3 for i in range(_str_len)]
            next_arr[0] = -1
            i, j = 0, -1
            while i<_str_len-1:
                if j == -1 or _str[i] == _str[j]:
                    j += 1
                    i += 1
                    next_arr[i] = j
                else:
                    j = next_arr[j]
            return next_arr
        next_arr = get_next(needle)
        i, j = 0, 0
        while i<h_len and j<n_len:
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = next_arr[j]
        if j == n_len:
            return i-j
        else:
            return -1

obj = Solution()
print(obj.strStr('hello', 'll'))
print(obj.strStr('aaaaa', 'bba'))
print(obj.strStr('a', 'a'))
print(obj.strStr('mississippi', 'issip'))

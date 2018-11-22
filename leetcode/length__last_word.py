class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        _str = s.strip()
        if len(_str) == 0:
            return 0
        return len(_str.split(' ')[-1])
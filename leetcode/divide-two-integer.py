class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if abs(dividend) < abs(divisor):
            return 0
        if (dividend>0 and divisor>0) or (dividend<0 and divisor<0):
            flag = 1
        else:
            flag = 0
        res = 0
        dividend, divisor = abs(dividend), abs(divisor)
        while dividend>=divisor:
            cnt = 0
            while dividend >= (divisor<<cnt):
                cnt += 1
            dividend -= divisor<<(cnt-1)
            res += (1<<(cnt-1))
        # 2147483648
        if res>=2147483648:
            if flag == 1:
                res = 2147483647

        res = -res if flag == 0 else res
        return res

obj = Solution()
print(obj.divide(1, 1))
print(obj.divide(10, 3))
print(obj.divide(-2147483648, -1))
print(obj.divide(-2147483648, 1))
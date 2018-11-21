class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        res = [[0]*n for i in range(n)]
        index = 1
        pos_x, pos_y = 0, 0
        direction = 0
        _x = [0, 1, 0, -1]
        _y = [1, 0, -1, 0]
        while index<=n*n:
            res[pos_x][pos_y] = index
            next_x = pos_x+_x[direction]
            next_y = pos_y+_y[direction]
            if next_x>=n or next_y>=n or next_x<0 or next_y<0 or res[next_x][next_y]:
                direction = (direction+1)%4
            pos_x = pos_x+_x[direction]
            pos_y = pos_y+_y[direction]
            index += 1
        return res
obj = Solution()
print(obj.generateMatrix(3))
print(obj.generateMatrix(4))
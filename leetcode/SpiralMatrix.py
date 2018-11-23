class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if matrix == []:
            return []
        res = []
        container = []
        m = len(matrix)
        n = len(matrix[0])
        _x = [0, 1, 0, -1]
        _y = [1, 0, -1, 0]
        index = 0
        direction = 0
        x, y = 0, 0
        while index<m*n:
            if matrix[x][y] is not False:
                res.append(matrix[x][y])
                matrix[x][y] = False
            next_x = x+_x[direction]
            next_y = y+_y[direction]
            if next_x>=m or next_x<0 or next_y>=n or next_y<0 or matrix[next_x][next_y] is False:
                direction = (direction+1)%4
            x = x+_x[direction]
            y = y+_y[direction]
            index += 1
        return res

obj = Solution()
print(obj.spiralOrder([
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]))

print(obj.spiralOrder([
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]))
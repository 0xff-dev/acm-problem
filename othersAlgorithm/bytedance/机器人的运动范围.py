class Solution:
    def movingCount(self, threshold, rows, cols):
        visited = [[0 for i in range(cols)] for i in range(rows)]
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        return self.moving(0, 0, rows, cols, threshold, visited, dirs)

    def moving(self, row, col, rows, cols, threshold, visited, dirs):
        if (row < 0 or row >= rows or col < 0 or col >= cols or 
            not self.is_ok(row, col, threshold) or visited[row][col] == 1):
            return 0
        visited[row][col] = 1
        res = 0
        for item in dirs:
            res += self.moving(row+item[0], col+item[1], rows, cols, 
                    threshold, visited, dirs)
        return res+1
    def is_ok(self, x, y, threshold):
        return sum(map(lambda x: int(x), list(str(x)+str(y)))) <= threshold

s = Solution()
print(s.movingCount(5, 10, 10))
print(s.movingCount(15, 20, 20))
print(s.movingCount(10, 1, 100))

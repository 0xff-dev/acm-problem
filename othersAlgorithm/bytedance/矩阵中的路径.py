class Solution:
    def hasPath(self, matrix, rows, cols, path):
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        x, y = 0, 0
        for x in range(rows):
            for y in range(cols):
                visited = [False for i in range(rows*cols)]
                if self.search(x, y, rows, cols, matrix, path, visited, dirs):
                    return True
        return False

    def search(self, x, y, rows, cols, matrix, path, visited, dirs):
        if path == '':
            return True
        if x < 0 or x >= rows or y < 0 or y >= cols or visited[x*cols+y]:
            return False
        res = False
        if matrix[x*cols+y] == path[0]:
            visited[x*cols+y] = True
            for item in dirs:
                res = (res or self.search(x+item[0], y+item[1], rows, cols, matrix, 
                    path[1:], visited, dirs))
        return res

s = Solution()
matrix = [
    ['a', 'b', 'c', 'e'],
    ['s', 'f', 'c', 's'],
    ['a', 'd', 'e', 'e']
]
matrix = 'abcesfcsadee'
print(s.hasPath(matrix, 3, 4, "bcced"))
print(s.hasPath(matrix, 3, 4, "abcb"))
print(s.hasPath(matrix, 3, 4, "abcced"))
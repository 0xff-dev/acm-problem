package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m, n := len(obstacleGrid), len(obstacleGrid[0])
	if m == 1 && n == 1 {
		if obstacleGrid[0][0] == 0 {
			return 1
		}
		return 0
	}
	auixMap := [101][101]int{}
	auixMap[0][0] = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if obstacleGrid[i][j] != 1 {
				if i != 0 && j == 0 {
					// 第一列
					if obstacleGrid[i-1][j] == 1 {
						auixMap[i][j] = 0
						obstacleGrid[i][j] = 1
					} else {
						auixMap[i][j] = auixMap[i-1][j]
					}
				} else if i == 0 && j != 0 {
					if obstacleGrid[i][j-1] == 1 {
						auixMap[i][j] = 0
						obstacleGrid[i][j] = 1
					} else {
						auixMap[i][j] = auixMap[i][j-1]
					}
				} else if i != 0 && j != 0 {
					auixMap[i][j] = auixMap[i-1][j] + auixMap[i][j-1]
					if auixMap[i][j] == 0 {
						obstacleGrid[i][j] = 1
					}
				}
			}
		}
	}
	return auixMap[m-1][n-1]
}

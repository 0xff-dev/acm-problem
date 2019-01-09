package main

import "fmt"

func uniquePaths(m int, n int) int {
	auxiMap := [101][101]int{}
	auxiMap[0][0] = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i != 0 && j == 0 {
				auxiMap[j][i] = auxiMap[j][i-1]
			} else if i == 0 && j != 0 {
				auxiMap[j][i] = auxiMap[j-1][i]
			} else if i != 0 && j != 0 {
				auxiMap[j][i] = auxiMap[j-1][i] + auxiMap[j][i-1]
			}
		}
	}
	return auxiMap[n-1][m-1]
}
func main() {
	fmt.Println(uniquePaths(23, 12))
	fmt.Println(uniquePaths(3, 2))
	fmt.Println(uniquePaths(7, 3))
}

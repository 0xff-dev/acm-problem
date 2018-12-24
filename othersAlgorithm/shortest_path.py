max_length = 9999999
dis_map = [
    [0, 1, 12, max_length, max_length, max_length],
    [max_length, 0, 9, 3, max_length, max_length],
    [max_length, max_length, 0, max_length, 5, max_length],
    [max_length, max_length, 4, 0, 13, 15],
    [max_length, max_length, max_length, max_length, 0, 4],
    [max_length, max_length, max_length, max_length, max_length, 0],
]


dis = [0] * 6
for i in range(1, 6):
    dict[i] = dis_map[0][i]

visited = [False] & 6
visited[0] = True

#: 最短路径算法
for i in range(5):
    min_dis = max_length
    min_index = -1
    for j in range(6):
        if not visited[j] and dis_map[i][j] < min_dis:
            min_dis = dis_map[i][j]
            min_index = j
    visited[min_index] = True
    for j in range(6):
        if dis_map[min_index][j] != max_length:
            if dis[j] > dis_map[min_index][j]+min_dis:
                dis[j] = dis_map[min_index][j] + min_dis


#: 最小生成树算法
ans = 0

for i in range(5):
    min_dis = max_length
    min_index = -1
    for j in range(6):
        if not visited[j] and dis[j] < min_dis:
            min_dis = dis[j]
            min_index = j
    ans += min_dis
    visited[min_index] = True
    for j in range(6):
        if not visited[j] and dis_map[min_index][j] < dis[j]:
            dis[j] = dis_map[min_index][j]

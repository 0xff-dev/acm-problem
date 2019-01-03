"""
最短路算法实现
0, 1, 2, 3, 4, 5 代表5个位置
0-1 = 1

"""

max_length = 9999999
dis_map = [
    [0, 1, 12, max_length, max_length, max_length],
    [max_length, 0, 9, 3, max_length, max_length],
    [max_length, max_length, 0, max_length, 5, max_length],
    [max_length, max_length, 4, 0, 13, 15],
    [max_length, max_length, max_length, max_length, 0, 4],
    [max_length, max_length, max_length, max_length, max_length, 0],
]


dis = [max_length] * 6
for i in range(6):
    dis[i] = dis_map[0][i]


visited = [False]*6
visited[0] = True


for i in range(5):
    min_dis = max_length
    min_index = -1
    for j in range(6):
        if not visited[j] and dis[j]< min_dis:
            min_dis = dis_map[i][j]
            min_index = j
    visited[min_index] = True
    for index in range(6):
       if dis_map[min_index][index] < max_length:
           if dis[index] > dis[min_index] + dis_map[min_index][index]:
               dis[index] = dis[min_index]+dis_map[min_index][index]
               
print(dis)


#: 最小生成树的算法

ans = 0
for i in range(5):
    min_dis = max_length
    min_index = -1
    for j in range(6):
        if not visited[j] and dis[j] < min_dis:
            min_dis = dis[j]
            min_index = j
    ans += min_dis
    visited[j] = True
    for j in range(6):
        if not visited[j] and dis[j] > dis_map[min_index][j]:
            dis[j] = dis_map[min_index][j]
print(dis)
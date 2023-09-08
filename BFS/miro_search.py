"""
0. 문제
- https://www.acmicpc.net/problem/2178

1. 아이디어
- bfs 탐색
- 1만 탐색 가능
- 다익스트라 처럼 해야 함

2. 시간복잡도
- O(V+E)
"""

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
maps = [[] for _ in range(N)]
check = [[0] * M for _ in range(N)]

for i in range(N):
    temp_list = input()
    maps[i].extend(temp_list[:-1])
    
def bfs(y, x):
    queue = [(y, x)]
    dy = [0, 1, -1, 0]
    dx = [1, 0, 0, -1]
    while queue:
        cy, cx = queue.pop(0)
        
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if 0 <= ny < N and 0 <= nx < M and \
            maps[ny][nx] == "1" and check[ny][nx] == 0:
                check[ny][nx] = check[cy][cx] + 1
                queue.append((ny, nx))
                
check[0][0] = 1        
bfs(0, 0)
print(check[N-1][M-1])
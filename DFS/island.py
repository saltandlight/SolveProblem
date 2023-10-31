'''
문제:
- https://www.acmicpc.net/problem/4963
아이디어:
- DFS
  재귀 함수 사용+visited 배열(boolean)
시간복잡도:
- O(V+E)
'''

import sys
sys.setrecursionlimit(10000)

input = sys.stdin.readline

def dfs(y, x, maps, check):
    check[y][x] = True
    
    dy = [0, 1, 1, 1, 0, -1, -1, -1]
    dx = [1, 1, 0, -1, -1, -1, 0, 1]
    
    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < len(maps) and 0 <= nx < len(maps[0]) \
        and check[ny][nx] == False and maps[ny][nx] == 1:
            check[ny][nx] = True
            dfs(ny, nx, maps, check)
            
total_cnt = []
while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    else:
        maps = []
        for _ in range(h):
            maps_row = list(map(int, input().split()))
            maps.append(maps_row)
        
        check = [[False] * w for _ in range(h)]
        cnt = 0
        for i in range(h):
            for j in range(w):
                if maps[i][j] == 1 and check[i][j] == False:
                    cnt += 1
                    dfs(i, j, maps, check)
        
        total_cnt.append(cnt)

for c in total_cnt:
    print(c)
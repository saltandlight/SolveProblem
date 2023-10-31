import sys

input = sys.stdin.readline
N = int(input())
maps = []
check = [[False] * N for _ in range(N)]

for i in range(N):
    maps_row = input().replace('\n', '')
    maps.append(maps_row)

def bfs(y, x, maps, check, N):
    que = [[y, x]]
    dy = [0, 0, -1, 1]
    dx = [1, -1, 0, 0]
    length = 1
    
    while que:
        y, x = que.pop()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= nx < N and 0 <= ny < N \
            and maps[ny][nx] == '1' and check[ny][nx] == False:
                check[ny][nx] = True
                length += 1
                que.append([ny, nx])
            
    return length

total_length = []
for i in range(N):
    for j in range(N):
        if maps[i][j] == '1' and check[i][j] == False:
            check[i][j] = True
            total_length.append(bfs(i, j, maps, check, N))

total_length = sorted(total_length)
print(len(total_length))
for tl in total_length:
    print(tl)

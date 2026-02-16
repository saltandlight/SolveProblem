import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T+1):
    N = int(input())
    
    map = [[0] * N for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    if N == 1:
        map = [[1]]
    else:
        curr = (0, 0)
        num = 1
        while num <= N * N:
            # 오른쪽 방향
            cy, cx = curr
            for j in range(cx, N):
                if not visited[cy][j]:
                    map[cy][j] = num
                    visited[cy][j] = True
                    num += 1
                    cx = j
            
            # 아래쪽 방향
            for i in range(cy, N):
                if not visited[i][cx]:
                    map[i][cx] = num
                    visited[i][cx] = True
                    num += 1
                    cy = i
                    
            # 왼쪽 방향
            for j in range(cx, -1, -1):
                if not visited[cy][j]:
                    map[cy][j] = num
                    visited[cy][j] = True
                    num += 1
                    cx = j
            
            # 위쪽 방향
            for i in range(cy, -1, -1):
                if not visited[i][cx]:
                    map[i][cx] = num
                    visited[i][cx] = True
                    num += 1
                    cy = i
            
            curr = (cy, cx)
    
    print(f"#{test_case}")
    for i in range(0, N):
        temp = map[i]
        result = ""
        for j in range(0, len(temp)):
            result += f"{str(temp[j])} "
        print(result)
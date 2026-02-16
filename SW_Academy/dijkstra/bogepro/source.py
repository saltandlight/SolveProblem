"""
1. 힙에 현재 좌표를 넣어줌, 비용도 함께 ex) [(w, y, x)] 
2. while heap 내부에서 어차피 이동할 수 있는 건 상,하,좌,우 -> dy, dx 이용해서 다음 좌표를 찾음, 다음 weight도
    - 힙에서 처음에 꺼내고 현재 값들 확인
    - 다음에 갈 수 있는 건 dy, dx 이용해서 얻고, 
    - 거리 비교 후, heappush 이용해서 push
3. 살아남는 건 어차피 최소 비용인 경우임 -> 힙에 넣어지는 것들은 다 최소 -> 따라서 heap에 넣을 때마다 더해주기
4. 이거 테스트케이스별로 출력
"""

import sys
import heapq

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline
INF = sys.maxsize

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

T = int(input())
for test_case in range(1, T+1):
    N = int(input())
    total_map = [list(map(int, input().strip())) for _ in range(N)]
        
    dist = [[INF] * N for _ in range(N)]
    S = (0, 0)
    G = (N-1, N-1)
    
    heap = [(0, 0, 0)] # w, y, x
    dist[0][0] = 0
    
    while heap:
        ew, ey, ex = heapq.heappop(heap)
        for d in range(4):
            ny = ey + dy[d]
            nx = ex + dx[d]
            if 0 <= nx < N and 0 <= ny < N:
                nw = total_map[ny][nx]
                if dist[ny][nx] > ew + nw:
                    dist[ny][nx] = ew + nw
                    heapq.heappush(heap, [dist[ny][nx], ny, nx])
            else:
                continue
        
    print(f"#{test_case} {dist[N-1][N-1]}")
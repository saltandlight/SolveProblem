'''
Idea) 
노드마다 자기 자신 제외한 1~N 노드까지의 거리를 다익스트라로 찾음
다익스트라는 여러 번 해야 함!
- 왜냐하면 시작점이 계속 바뀜
- 시작점으로부터 다른 노드들까지의 거리들의 합을 구하는 거임
- 즉, 시작점이 바뀔 떄마다 이 dist가 초기화되어야 함



'''

import sys
import heapq

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

# 20
# 5 0 1 1 0 0 1 0 1 1 1 1 1 0 0 0 0 1 0 0 0 0 1 0 0 0
# 5 0 0 1 1 0 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 0 0 1 1 0

INF = sys.maxsize
T = int(input())

for test_case in range(1, T+1):
    item_list = list(map(int, input().split()))
    N = item_list[0]
    item_list[0] = 0
    
    edge = [[] for _ in range(N+1)]
    
    for idx in range(1,len(item_list)):
        u = (idx // N) + 1
        v = idx % N
        if v == 0:
            v = N
            u -= 1
        
        if item_list[idx] == 1:
            edge[u].append(v)
    
    min_sum = INF
    for K in range(1, N+1):
        dist = [INF] * (N+1)
        dist[K] = 0
        heap = [[0, K]]
        
        while heap:
            ew, ev = heapq.heappop(heap)
            if dist[ev] != ew: continue
            for nv in edge[ev]:
                if dist[nv] > ew + 1:
                    dist[nv] = ew + 1
                    heapq.heappush(heap, [dist[nv], nv])
                    
        sum = 0
        for i in range(1, N+1):
            if dist[i] == INF: continue
            else: sum += dist[i]
        
        if min_sum >= sum:
            min_sum = sum
    
    print(f"#{test_case} {min_sum}")
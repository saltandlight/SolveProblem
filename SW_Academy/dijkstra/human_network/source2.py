import sys
import heapq

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())
INF = 987654321

for test_case in range(1, T+1):
    item_list = list(map(int, input().split()))
    N = item_list[0]
    item_list[0] = 0
    
    edges = [[] for _ in range(N+1)]
    for i in range(1, N*N+1):
        u = (i // N) + 1
        v = i % N
        
        if v == 0:
            u -= 1
            v = N
        
        if item_list[i] == 1:
            edges[u].append(v)
    
    min_num = INF
    for K in range(1, N+1):
        dist = [INF] * (N+1)
        dist[K] = 0
        heap = [[0, K]]
        
        while heap:
            ew, ev = heapq.heappop(heap)
            if dist[ev] != ew: continue
            for nv in edges[ev]:
                if dist[nv] > ew + 1:
                    dist[nv] = ew + 1
                    heapq.heappush(heap, [dist[nv], nv])
        
        dist_sum = 0
        for d in dist:
            if d != INF:
                dist_sum += d
        
        if min_num > dist_sum:
            min_num = dist_sum
            
    print(f"#{test_case} {min_num}")
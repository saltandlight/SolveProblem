import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

V, E = map(int, input().split())
K = int(input())

edges = [[] for _ in range(V+1)]

for i in range(V+1):
    u, v, w = map(int, input().split())
    edges[u].append([w, v])

dist = [INF] * (V+1)
dist[K] = 0

heap = [[0, K]]
while heap:
    cw, cv = heapq.heappop(heap)
    if dist[cv] != cw: continue
    for nw, nv in edges[cv]:
        if dist[nv] > cw + nw:
            dist[nv] = cw + nw
            heapq.heappush(heap, [dist[nv], nv])

for i in range(1, len(dist)):
    if dist[i] == INF: print("INF")
    else: print(dist[i])
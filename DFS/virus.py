"""
0. 문제
- https://www.acmicpc.net/problem/2606

1. 아이디어
- DFS

2. 시간복잡도
- O(V+E)

3. 자료구조
- 큐
- 양방향 간선 담을 수 있는 edge[][]
- visited boolean 배열
"""

import sys
input = sys.stdin.readline

V = int(input())
E = int(input())
edge = [[] * (V+1) for _ in range(V+1)]
visited = [False] * (V+1)
for i in range(E):
    u, v = map(int, input().split())
    edge[u].append(v)
    edge[v].append(u)

global total_num 
total_num = -1

def DFS(st):
    visited[st] = True
    global total_num
    total_num += 1
    
    for nv in edge[st]:
        if visited[nv] == False:
            DFS(nv)

DFS(1)
print(total_num)
'''
아이디어: 
- DFS
  stack 사용
  재귀함수+visited 배열(boolean)
- BFS
  큐 사용
  while loop 사용+visited 배열(boolean)
시간복잡도:
- O(V+E)
'''

import sys
input = sys.stdin.readline

def dfs(point, visited, edge, dfs_list):
    visited[point] = True
    dfs_list.append(str(point))
    
    for v in edge[point]:
        if visited[v] == False:
            dfs(v, visited, edge, dfs_list)

def bfs(point, visited, edge, bfs_list):
    queue = [point]
    visited[point] = True
    
    while queue:
        visit_v = queue.pop(0)
        bfs_list.append(str(visit_v))
        
        for v in edge[visit_v]:
            if visited[v] == False:
                visited[v] = True
                queue.append(v)
    
    return bfs_list

n, m, start = map(int, input().split())

edge = [[] for _ in range(n+1)]
visitied = [False] * (n+1)
dfs_list = []

for k in range(m):
    u, v = map(int, input().split())
    edge[u].append(v)
    edge[v].append(u)

edge_sorted = []
for e in edge:
    edge_sorted.append(sorted(e))

dfs(start, visitied, edge_sorted, dfs_list)
dfs_result = " ".join(dfs_list)
print(dfs_result)

visitied = [False] * (n+1)
bfs_list = []
bfs_result = bfs(start, visitied, edge_sorted, bfs_list)
print(" ".join(bfs_result))
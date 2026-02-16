import sys
sys.setrecursionlimit(10**6)

sys.stdin = open("s_input.txt", "r")
input = sys.stdin.readline

T = int(input())

def dfs(node, visited, edges):
    visited[node] = True
    
    for nu in edges[node]:
        if visited[nu] == False:
            dfs(nu, visited, edges)
                
for test_case in range(1, T+1):
    N, M = map(int, input().split())
    edges = [[] for _ in range(N+1)]
    visited = [False] * (N+1)
    
    for i in range(M):
        u, v = map(int, input().split())
        
        edges[u].append(v)
        edges[v].append(u)


    cnt = 0
    for i in range(1, N+1):
        if visited[i] == False:
            dfs(i, visited, edges)
            cnt += 1
    
    print(f"#{test_case} {cnt}")
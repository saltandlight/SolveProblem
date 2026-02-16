# 10
# 13 12 8 13
# 1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 10 6 11 11 13

import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T + 1):
    V, E, node1, node2 = map(int, input().split())
    item = list(map(int, input().split()))
    
    parent = [0] * (V+1)
    children = [[] for _ in range(V+1)]
    
    for i in range(0, len(item), 2):
        par = item[i]
        child = item[i+1]
        children[par].append(child)
        parent[child] = par
        
    par_node1 = []
    while parent[node1] != 0:
        par_node = parent[node1]
        par_node1.append(par_node)
        node1 = par_node

    par_node2 = []
    common_parent = 0
    while parent[node2] != 0:
        par_node = parent[node2]
        
        if par_node in par_node1:
            common_parent = par_node
            break
        par_node2.append(par_node)
        node2 = par_node
    
    cnt = 1
    def count_child(node):
        global cnt
        if len(children[node])==0:
            return 0

        else:
            for ch in children[node]:
                cnt += 1
                count_child(ch)
            
    count_child(common_parent)
    #1 3 8
    print(f"#{test_case} {common_parent} {cnt}")
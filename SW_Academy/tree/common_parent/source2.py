import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())

def count_children_num(node, children):
    global children_cnt 
    
    if node == 0:
        return
    
    if len(children[node]) >= 1:
        count_children_num(children[node][0], children)
    
    children_cnt += 1
    if len(children[node]) > 1:
        count_children_num(children[node][1], children)       
            
for test_case in range(1, T+1):
    V, E, N, M = map(int, input().split())
    tree_list = list(map(int, input().split()))

    parent = [0] * (V+1)
    children = [[] for _ in range(V+1)]
    
    for i in range(0, len(tree_list)-1, 2):
        p, c = tree_list[i], tree_list[i+1]
        parent[c] = p
        children[p].append(c)
        
    n_parents = set()
    n = N
    while parent[n] != 0:
        par = parent[n]
        if par not in n_parents:
            n_parents.add(par)
            n = par
    
    m_parents = []
    m = M
    common_par = 0
    while parent[m] != 0:
        m_par = parent[m]
        if m_par in n_parents:
            common_par = m_par
            break
        else:
            m = m_par
    
    children_cnt = 0
    
    count_children_num(common_par, children)
    print(f"#{test_case} {common_par} {children_cnt}")
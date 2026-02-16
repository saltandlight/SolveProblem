import sys
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = 10
for test_case in range(1, T+1):
    V = int(input())
    
    parent = [0] * (V+1)
    children = [[] for _ in range(V+1)]
    chr_dict = {}
    result = ""
    for v in range(V):
        item = list(map(str, input().split()))
        
        num = int(item[0])
        ch = item[1]
        chr_dict[num] = ch
        
        if len(item) > 2:
            for c in item[2:]:
                c2 = int(c)
                children[num].append(c2)
                parent[c2] = num
        
    # 1 SOFTWARE
    def inorder(node):
        global result
        
        if len(children[node]) >= 1:
            inorder(children[node][0])
        
        result += chr_dict[node]
        if len(children[node]) > 1:
            inorder(children[node][1])
            
    inorder(1)
    print(f"#{test_case} {result}")
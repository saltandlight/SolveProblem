import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = 10

for test_case in range(1, T + 1):
    V = int(input())
    parent = [0] * (V+1)
    children = [[] for _ in range(V+1)]
    ch_dict = {}
    result = ""
    
    def evaluate(node):
        # 현재 노드
        val = ch_dict[node]
        
        if not children[node]:
            return int(val)
        
        left = evaluate(children[node][0])
        right = evaluate(children[node][1])
        if val == '-':
            return left - right
        elif val == '+':
            return left + right
        elif val == '/':
            return left / right
        elif val == '*':
            return left * right

    for v in range(V):
        item_list = list(map(str, input().split()))
        num = int(item_list[0])
        ch = item_list[1]
        if len(item_list) > 2:
            for c in item_list[2:]:
                c2 = int(c)
                children[num].append(c2)
                parent[c2] = num

        ch_dict[num] = ch
        
    calc = int(evaluate(1))
    
    
    #10 2
    print(f"#{test_case} {calc}")
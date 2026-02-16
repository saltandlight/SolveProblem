import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = 10

def evaluate(node):
    arith_list = ['-', '+', '/', '*']
    val = str_dict[node]
    global result
    if not children[node]:
        if val in arith_list:
            result *= 0
            return 0
        else:
            return int(val)
    elif len(children[node])== 2:
        left = evaluate(children[node][0])
        right = evaluate(children[node][1])
        
        if left not in arith_list \
        and right not in arith_list \
        and val in arith_list:
            pass
        else:
            result *= 0


for test_case in range(1, T + 1):
    V = int(input())
    
    parent = [0] * (V+1)
    children = [[] for _ in range(V+1)]
    str_dict = {}
    result = 1
    
    for v in range(1, V+1):
        item = list(map(str, input().split()))
        # 85 * 170 171
        # 86 4
        num = int(item[0])
        st = item[1]
        str_dict[num]=st
        
        if len(item[2:]) > 0:
            for c in item[2:]:
                c2 = int(c)
                parent[c2] = num
                children[num].append(c2)
    
    evaluate(1)
    print(f"#{test_case} {result}")
                
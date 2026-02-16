import sys

sys.stdin = open("sample_input.txt", "r")
input = sys.stdin.readline

# 3
# 3 2
# 1 5 3
# 8 3

T = int(input())
for test_case in range(1, T+1):
    len_con, len_t = map(int, input().split())
    
    con_lst = list(map(int, input().split()))
    truck_lst = list(map(int, input().split()))
    
    con_lst.sort(reverse=True)
    truck_lst.sort(reverse=True)
    
    result = 0
    c_idx = 0
    t_idx = 0
    
    while t_idx < len_t and c_idx < len_con:
        if con_lst[c_idx] <= truck_lst[t_idx]:
            result += con_lst[c_idx] 
            c_idx += 1
            t_idx += 1
        else:
            c_idx += 1

    print(f"#{test_case} {result}")
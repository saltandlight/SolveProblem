import sys

sys.stdin = open("sample_input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T+1):
    N = int(input())
    item_list = []
    for n in range(1, N+1):
        item = tuple(map(int, input().split()))
        item_list.append(item)
    
    # print(item_list)
    item_list.sort(key=lambda x: x[1])
    result = 0
    
    curr = item_list[0]
    for i in range(1, len(item_list)):
        first_st, first_end = curr
        second_st, second_end = item_list[i]
        
        if second_st >= first_end:
            result += 1
            curr = (second_st, second_end)
    
    print(f"#{test_case} {result+1}")
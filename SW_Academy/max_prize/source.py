import sys
from itertools import combinations

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())

for tc in range(1, T+1):
    num_str, cnt = input().split()
    cnt = int(cnt)
    
    curr_states = {num_str}
    result = -1000000
    for _ in range(cnt):
        new_states = set()
    
        for c_state in curr_states:
            lst = list(c_state)
            for i in range(len(c_state)):
                for j in range(i+1, len(c_state)):
                    lst[i], lst[j] = lst[j], lst[i]
                    new_states.add("".join(lst))
                    lst[j], lst[i] = lst[i], lst[j]
                    
        if not new_states:
            break
        curr_states = new_states
    result = max(map(int, curr_states))
    print(f"#{tc} {result}")
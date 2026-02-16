import sys
from itertools import combinations

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T+1):
    num, N = map(int, input().split())
    str_num = list(str(num).strip())
    index_list = [i for i in range(len(str_num))]
    
    comb_list = list(combinations(index_list, 2))
    max_num = -987654321
    visited = set()
    
    def swap_card(card_num, cnt):
        global max_num
        
        state = (''.join(card_num), cnt)
        if state in visited:
            return  
        visited.add(state)
        
        if cnt == N:
            max_num = max(max_num, int(''.join(card_num)))
            return
        
        for comb in comb_list:
            curr, next = comb
            card_num[next], card_num[curr] = card_num[curr], card_num[next]
            swap_card(card_num, cnt+1)
            card_num[curr], card_num[next] = card_num[next], card_num[curr]
                
    
    swap_card(str_num, 0)
    print(f"#{test_case} {max_num}")
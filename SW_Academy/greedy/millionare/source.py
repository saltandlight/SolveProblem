import sys
# from collections import deque

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())

for test_case in range(1, T+1):
    N = int(input())
    item_list = list(map(int, input().split()))
    max_list = []
    result = 0
    
    max_val = 0
    for num in reversed(item_list):
        if num > max_val:
            max_val = num
        else: # num <= max_val
            result += max_val - num
        
    print(f"#{test_case} {result}")
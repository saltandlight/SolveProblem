import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T+1):
    num_list = list(map(int, input().split()))
    
    num_list.sort()

    sum = 0
    for num in num_list[1:-1]:
        sum += num
    
    medium = sum / len(num_list[1:-1])
    medium = round(medium)
    print(f"#{test_case} {medium}")
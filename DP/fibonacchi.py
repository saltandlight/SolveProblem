"""
0. 문제
- https://www.acmicpc.net/problem/1003

1. 아이디어
- DP

2. 시간복잡도
- O(N*T)

3. 자료구조
- 리스트
"""

import sys
input = sys.stdin.readline

N = int(input())
num_list = []
for i in range(N):
    num = int(input())
    num_list.append(num)

for num in num_list:
    arr = [[1, 0], [0, 1]]
    if num >= 2:
        for j in range(2, num+1):
            num_z = arr[j-1][0] + arr[j-2][0]
            num_f = arr[j-1][1] + arr[j-2][1]
            arr.append([num_z, num_f])
            
    print(f"{arr[num][0]} {arr[num][1]}")
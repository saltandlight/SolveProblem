'''
1. 문제
- https://www.acmicpc.net/problem/1003
2. 아이디어
- DP
  - 이전 fibonachi 0, 1값을 지속적으로 더하기
3. 시간복잡도
- O(N*T)
'''

import sys

input = sys.stdin.readline
T = int(input())
test_case = []
for t in range(T):
    t_input = int(input())
    test_case.append(t_input)
    
fibo_0 = [1, 0]
fibo_1 = [0, 1]
max_t = max(test_case)
if max_t >= 2:
    for i in range(2, max_t+1):
        fibo_0.append(fibo_0[i-1] + fibo_0[i-2])
        fibo_1.append(fibo_1[i-1] + fibo_1[i-2])

for tc in test_case:
    print(f'{fibo_0[tc]} {fibo_1[tc]}')
    
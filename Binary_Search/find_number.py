'''
0. 문제
- https://www.acmicpc.net/problem/1920
1. 아이디어
- 이진 탐색
  - 먼저 source 리스트를 정렬
  - 정렬한 리스트를 절반으로 나누어 중앙에 있는 원소를 탐색대상의 수와 비교
2. 시간복잡도
- O(logn)
'''

import sys
sys.setrecursionlimit(10000)

input = sys.stdin.readline

N = int(input())
src_nums = list(map(int, input().split()))

M = int(input())
tgt_nums = list(map(int, input().split()))

src_nums = sorted(src_nums)
def binary_search(target, s, e):
    if s >= e:
        if target == src_nums[s]:
            print(1)
        else:
            print(0)
        return
    
    mid = (s + e) // 2
    if target <= src_nums[mid]:
        binary_search(target, s, mid)
    else:
        binary_search(target, mid+1, e)
    

for tgt in tgt_nums:
    binary_search(tgt, 0, N-1)
"""
출발지: 회사
중간 방문지들: N명의 고객
도착지: 집

최적의 경로만 찾으면 됨
꼭 효율적일 필요는 없다.

다익스트라를 쓰는 게 맞음 
2차원으로 하되 dist의 경우, 일일히 계산해야 함
점과 다음 점을 알게 되면 dist를 일일히 계산해서 새로운 w로 보는 게 맞겠음
"""

import sys
from itertools import permutations

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline
INF = 987654321

T = int(input())

def compute_dist(x1, y1, x2, y2):
    dist = abs(x1-x2) + abs(y1-y2)
    return dist

for test_case in range(1, T+1):
    N = int(input())
    item_list = list(map(int, input().split()))
    
    company = (item_list[0], item_list[1])
    home = (item_list[2], item_list[3])
    item_list = item_list[4:]
    
    customer_list = []
    for i in range(0, len(item_list)-1, 2):
        temp = (item_list[i], item_list[i+1])
        customer_list.append(temp)
    
    visited = [False] * N
    min_dist = INF
    
    def dfs(curr_x, curr_y, dist, cnt):
        global min_dist
        
        if min_dist <= dist:
            return 
        
        if cnt == N:
            dist += abs(curr_x - home[0]) + abs(curr_y - home[1])
            if min_dist >= dist:
                min_dist = dist
            return
            
        for i in range(N):
            if not visited[i]:
                visited[i] = True
                next_x, next_y = customer_list[i]
                next_dist = dist + abs(curr_x - next_x) + abs(curr_y - next_y)
                dfs(next_x, next_y, next_dist, cnt+1)
                visited[i] = False
            
    dfs(company[0], company[1], 0, 0)
    print(f"#{test_case} {min_dist}")
'''
Docstring for ladder1.ladder
1. 가장 윗 줄에서 1인 애를 고름
2. 고른 애에서 이제 아래로 이동하다가 좌, 우 방향이 나오면 좌로 가는 거, 우로 가는 거 둘 다 호출
3. 도착하게 되면 출발점을 정답으로 하기 (이걸 계속 저장을 해야 함) -> start point를 따로 저장
'''
import sys
from collections import deque
# 이 부분만 추가하면 됩니다!
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

for t in range(10):
    tc = int(input())
    
    dy = [0, 0, -1]
    dx = [-1, 1, 0]
    ladder = [list(map(int, input().split())) for _ in range(100)]
    visited = [[False] * 100 for _ in range(100)]
    start_point = ()
    answer = []
    
    # start point 찾기
    for i in range(100):
        if ladder[99][i] == 2:
            start_point = (99, i)
            visited[99][i] = True
    
    y, x = start_point
    
    while y > 0:        
        for d in range(3):
            next_y = y + dy[d]
            next_x = x + dx[d]
            
            if 0 <= next_y < 100 and 0 <= next_x < 100 \
            and visited[next_y][next_x] == False \
            and ladder[next_y][next_x] == 1:
                visited[next_y][next_x] = True
                x = next_x
                y = next_y
                break
    
    if y == 0 and ladder[y][x] == 1:
        print(f"#{t+1} {x}")
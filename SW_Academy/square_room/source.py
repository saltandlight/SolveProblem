import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T+1):
    N = int(input())
    room = []
    checked = [0] * (N * N + 1) 
    for i in range(N):
        row_room = list(map(int, input().split()))
        room.append(row_room)
    
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    
    for i in range(N):  # y 방향
        for j in range(N):  # x 방향
            for d_idx in range(4):
                neigh_y = i + dy[d_idx]
                neigh_x = j + dx[d_idx]
                
                if 0 <= neigh_y < N  and 0 <= neigh_x < N:
                    curr_room = room[i][j]
                    cal = room[neigh_y][neigh_x] - curr_room
                    if cal == 1:
                        checked[curr_room] = 1
    
    max_cnt = 0
    ans_room = 0
    current_cnt = 0
    for c_idx in range(len(checked)-1, -1, -1):
        if checked[c_idx] == 1:
            current_cnt += 1
        else:
            dist = current_cnt + 1
            
            if dist >= max_cnt:
                ans_room = c_idx
                max_cnt = dist

            current_cnt = 0

    print(f"#{test_case} {ans_room+1} {max_cnt}")
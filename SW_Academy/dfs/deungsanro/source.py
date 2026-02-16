import sys

sys.stdin = open("sample_input.txt", "r")
input = sys.stdin.readline

# 10
# 5 1
# 9 3 2 3 2
# 6 3 1 7 5
# 3 4 8 9 9
# 2 3 7 7 7
# 7 6 5 5 8

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

T = int(input())
for test_case in range(1, T+1):
    N, K = map(int, input().split())
    item_list = [list(map(int, input().split())) for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    
    start_num = -1
    start_point_list = []
    for i in range(N):
        start_num = max(start_num, max(item_list[i]))
    

    def dfs(curr_y, curr_x, cnt, can_cut):
        global max_len
        max_len = max(max_len, cnt)
        
        for d_idx in range(4):
            next_x, next_y = curr_x + dx[d_idx], curr_y + dy[d_idx]
            
            if 0 <= next_x < N and 0 <= next_y < N \
            and not visited[next_y][next_x]:
                curr_h = item_list[curr_y][curr_x]
                next_h = item_list[next_y][next_x]
                if curr_h > next_h:
                    visited[next_y][next_x] = True
                    dfs(next_y, next_x, cnt+1, can_cut)
                    visited[next_y][next_x] = False
                    
                elif can_cut and curr_h > (next_h - K):
                    visited[next_y][next_x] = True
                    temp = item_list[next_y][next_x]
                    item_list[next_y][next_x] = item_list[curr_y][curr_x] - 1
                    
                    dfs(next_y, next_x, cnt + 1, False)
                    item_list[next_y][next_x] = temp
                    visited[next_y][next_x] = False
                    
    max_len = -987654321
    for i in range(N):
        for j in range(N):
            if start_num == item_list[i][j]:
                visited[i][j] = True
                dfs(i, j, 1, True)
                visited[i][j] = False
                
    
    # 끝 point에서 찾아보기
    print(f"#{test_case} {max_len}")
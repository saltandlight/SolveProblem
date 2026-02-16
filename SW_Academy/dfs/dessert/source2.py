import sys

sys.stdin = open("sample_input.txt", "r")
input = sys.stdin.readline

# 10
# 4
# 9 8 9 8
# 4 6 9 4
# 8 7 7 8
# 4 5 3 5

dy = [1, 1, -1, -1]
dx = [1, -1, -1, 1]

T = int(input())
for test_case in range(1, T+1):
    N = int(input())
    item_list = [list(map(int, input().split())) for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    
    def dfs(curr_x, curr_y, d_idx, cnt):
        global max_len, start_x, start_y, visit_num        
        
        for i in range(d_idx, d_idx+2):
            if i >= 4: break
            
            next_x, next_y = curr_x + dx[i], curr_y + dy[i]
            if next_x == start_x and next_y == start_y:
                if cnt >= 3:
                    max_len = max(max_len, cnt+1)
                return
        
            if 0 <= next_x < N and 0 <= next_y < N:
                if item_list[next_y][next_x] not in visit_num:
                    visit_num.add(item_list[next_y][next_x])
                    dfs(next_x, next_y, i, cnt+1)
                    visit_num.remove(item_list[next_y][next_x])
    
    visit_num = set()
    max_len = -1
    for i in range(N-2):
        for j in range(1, N):
            start_x, start_y = j, i
            visit_num.add(item_list[i][j])
            dfs(j, i, 0, 0)
            visit_num.remove(item_list[i][j])
    
    
    print(f"#{test_case} {max_len}")
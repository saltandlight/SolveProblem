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
    dessert_map = [list(map(int, input().split())) for _ in range(N)]
    
    
    max_cnt = -1
    visited = set()
    def dfs(curr_x, curr_y, d_idx, cnt):
        global max_cnt, start_x, start_y
        
        # # 종료조건
        # if d_idx == 3 and curr_x+dx[3] == start_x and curr_y+dy[3] == start_y:
        #     max_cnt = max(max_cnt, cnt)
        #     return
        
        # 그 외
        for i in range(d_idx, d_idx + 2):
            if i < 4:
                next_y = curr_y + dy[i]
                next_x = curr_x + dx[i]
                
                # 1. 이동할 곳이 시작점이고, 최소 사각형(4칸) 이상인 경우
                if next_y == start_y and next_x == start_x and cnt >= 3:
                    max_cnt = max(max_cnt, cnt + 1)
                    return
                
                if 0 <= next_y < N and 0 <= next_x < N:
                    if dessert_map[next_y][next_x] not in visited:
                        visited.add(dessert_map[next_y][next_x])
                        dfs(next_x, next_y, i, cnt+1)
                        visited.remove(dessert_map[next_y][next_x])
        
    
    for i in range(N-2):
        for j in range(1, N-1):
            visited.add(dessert_map[i][j])
            start_x, start_y = j, i
            dfs(j, i, 0, 0)
            visited.clear()
            
    print(f"#{test_case} {max_cnt}")
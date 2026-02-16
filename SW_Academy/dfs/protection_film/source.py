import sys

sys.stdin = open("sample_input.txt", "r")
input = sys.stdin.readline

# 각 열마다 연속한 수가 얼마인 지 체크
def check(item_list, W, K):
    # item_list[0][0], item_list[1][0] ~ item_list[5][0] 끼리 얼마나 연속한 수가 있는 지 확인
    # item_list[0][1], item_list[1][1] ~ item_list[5][1] 
    # item_list[0][2], item_list[1][2] ~ item_list[5][2]
    # ...
    for j in range(0, W):
        cnt = 1
        passed = False
        for i in range(1, D):
            if item_list[i][j] == item_list[i-1][j]:
                cnt += 1
            else:
                cnt = 1
                
            if cnt >= K:
                passed = True
                break
            
        if not passed:
            return False
    return True
                

T = int(input())        
for test_case in range(1, T+1):
    D, W, K = map(int, input().split())
    item_list = [list(map(int, input().split())) for _ in range(D)]
    
    result = check(item_list, W, K)
    ans = 0
    
    def dfs(idx, D, W, call_cnt):
        global ans, item_list

        if call_cnt >= ans:
            return
        
        if idx == D:
            result = check(item_list, W, K)
            if result:
                ans = call_cnt
            return
        
        dfs(idx+1, D, W, call_cnt)
                
        original_row = item_list[idx][:]
        # A로 진행 
        item_list[idx] = [0] * W
        dfs(idx+1, D, W, call_cnt+1)
        
        # B로 진행
        item_list[idx] = [1] * W
        dfs(idx+1, D, W, call_cnt+1)
        
        item_list[idx] = original_row

    if result:
        print(f"#{test_case} {ans}")
    else:
        ans = K
        dfs(0, D, W, 0)
        print(f"#{test_case} {ans}")

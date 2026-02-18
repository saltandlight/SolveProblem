import sys

"""
1. 일단 열마다 연속한 특징이 K개가 넘는 지 확인  -> check() 함수 정의
2. 현재 상태가 만약 K개가 넘으면 0을 그대로 출력
3. 아니면 dfs로 계속 상태 체크
  - 어차피 row별로 처리하게 되어있음
  - check 를 해주는데 이게 True면 이미 뭐 더 이상 조치가 안 필요함. -> 리턴시켜버리기
    (이걸 초반에...)
  - 현재 상태 -> 다음 상태 (check해줌)
  - 현재 상태에서 해당 row를 다 0으로 해줌 -> check해줌
  - 현재 상태에서 해당 row를 다 1로 해줌 -> check해줌
  - 다 원복... 
"""

# 10
# 6 8 3
# 0 0 1 0 1 0 0 1
# 0 1 0 0 0 1 1 1
# 0 1 1 1 0 0 0 0
# 1 1 1 1 0 0 0 1
# 0 1 1 0 1 0 0 1
# 1 0 1 0 1 1 0 1

sys.stdin = open("sample_input.txt", "r")
input = sys.stdin.readline

def check(film, W, D, K):
    result_flag = True
    
    # 열로 접근
    for j in range(0, W):
        cnt = 1
        for i in range(1, D):
            if film[i][j] == film[i-1][j]:
                cnt += 1
            
                if cnt >= K: break
            else:
                cnt = 1
        
        if cnt < K:
            result_flag = False
        
    return result_flag
    
T = int(input())
for test_case in range(1, T+1):
    D, W, K  = map(int, input().split())
    
    film = [list(map(int, input().split())) for _ in range(D)]
    
    result = check(film, W, D, K)
    ans = D
    
    def dfs(idx, D, cnt):
        global ans, film
        
        if cnt >= ans:
            return
        
        if idx == D:
            result = check(film, W, D, K)
            if result:
                ans = min(ans, cnt)
            return

        dfs(idx+1, D, cnt)
        
        backup = film[idx][:]
        
        film[idx] = [0] * W
        dfs(idx+1, D, cnt+1)
        
        film[idx] = [1] * W
        dfs(idx+1, D, cnt+1)
        
        film[idx] = backup
    
    dfs(0, D, 0)
    print(f"#{test_case} {ans}")
import sys

sys.stdin = open("sample_input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T+1):
    N, M = map(int, input().split())
    city = []
    target_home = []
    for i in range(1, N+1):
        temp = list(map(int, input().split()))
        city.append(temp)
    
    for i in range(N):
        for j in range(N):
            if city[i][j] == 1:
                item = (i, j)
                target_home.append(item)
    
    result = 0
    for k in range(1, N*2):
        max_num = -10000
        cost = k * k + (k-1) * (k-1)
        for r in range(N):
            for c in range(N):
                target_num = 0
                for home in target_home:
                    i, j = home
                    dist = abs(r-i) + abs(c-j)
                    if dist < k:
                        target_num += 1 
               
                if max_num <= target_num:
                    max_num = target_num
        
        # 보안회사의 이익 계산
        if M * (max_num) - cost >= 0 \
        and result < max_num:
            result = max_num
        
    print(f"#{test_case} {result}")
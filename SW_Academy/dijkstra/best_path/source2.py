import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline


# 10
# 5
# 0 0 100 100 70 40 30 10 10 5 90 70 50 20

T = int(input())
for test_case in range(1, T+1):
    N = int(input())
    item_list = list(map(int, input().split()))
    
    company = (item_list[0], item_list[1])
    home = (item_list[2], item_list[3])
    
    customer_list = []
    for i in range(4, 2*N+3, 2):
        x, y = item_list[i], item_list[i+1]
        customer_list.append((x, y))
        
    # print(customer_list)

    min_dist = 987654321
    visited = [False] * N
        
    def dfs(curr_x, curr_y, dist, cnt):
        global min_dist
        
        if dist > min_dist:
            return
        
        if cnt == N:
            dist += abs(curr_x - home[0]) + abs(curr_y - home[1])
            if min_dist <= dist:
                return
            min_dist = dist
        else:
            for i in range(N):
                if not visited[i]:
                    next_x, next_y = customer_list[i]
                    visited[i] = True
                    curr_dist = dist + abs(curr_x - next_x) + abs(curr_y - next_y)                    
                    dfs(next_x, next_y, curr_dist, cnt+1)
                    visited[i] = False
    
    dfs(company[0], company[1], 0, 0)
    print(f"#{test_case} {min_dist}")
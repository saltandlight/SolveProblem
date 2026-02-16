import sys

sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

T = int(input())
for test_case in range(1, T+1):
    N, K = map(int, input().split())
    
    puzzle = []
    
    for y in range(N):
        temp = list(map(int, input().split()))
        puzzle.append(temp)
    
    total_cnt = 0
    target_str = '1' * K
    
    for y in range(N):
        puzzle_y_list = ''.join(map(str, puzzle[y])).split("0")
        for puz in puzzle_y_list:
            if target_str == puz:
                total_cnt += 1

    for x in range(N):        
        temp = [puzzle[y][x] for y in range(N)]
        puzzle_x_list = ''.join(map(str, temp)).split("0")
        for puz in puzzle_x_list:
            if target_str == puz:
                total_cnt += 1
        
    print(f"#{test_case} {total_cnt}")
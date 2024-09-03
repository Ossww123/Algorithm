def solve(total_x, total_y, plus_cnt = 1, minus_cnt = 0):
    global result
    
    cnt = plus_cnt + minus_cnt
    
    if cnt == N:
        result = min(result, total_x ** 2 + total_y ** 2)
        return 
    
    if plus_cnt < N//2:
        solve(total_x + worms[cnt][0], total_y + worms[cnt][1], plus_cnt + 1, minus_cnt)
    if minus_cnt < N//2:
        solve(total_x - worms[cnt][0], total_y - worms[cnt][1], plus_cnt, minus_cnt + 1)
    
    

T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    worms = [list(map(int, input().split())) for _ in range(N)]
    result = float('inf')

    solve(worms[0][0], worms[0][1])
    print(f'#{tc} {result}')
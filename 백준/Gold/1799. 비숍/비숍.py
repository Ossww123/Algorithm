N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

# 흑백 체스판으로 나누기
white = []
black = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            if (i + j) % 2 == 0:
                white.append((i, j))
            else:
                black.append((i, j))

def solve(bishops):
    n = len(bishops)
    diag1 = [0] * (2 * N)
    diag2 = [0] * (2 * N)
    
    def dfs(index, count):
        if index == n:
            return count
        
        y, x = bishops[index]
        res = dfs(index + 1, count)  # 현재 위치에 비숍을 놓지 않는 경우
        
        if not diag1[y+x] and not diag2[y-x+N]:
            diag1[y+x] = diag2[y-x+N] = 1
            res = max(res, dfs(index + 1, count + 1))  # 현재 위치에 비숍을 놓는 경우
            diag1[y+x] = diag2[y-x+N] = 0
        
        return res
    
    return dfs(0, 0)

# 흰색 칸과 검은색 칸에 대해 각각 계산
result = solve(white) + solve(black)
print(result)
N = int(input())

cnt = 0
col = [0] * N
diag1 = [0] * (2*N-1)
diag2 = [0] * (2*N-1)

def backtrack(row=0):
    global cnt

    if row == N:
        cnt += 1
        return

    for j in range(N):
        if not (col[j] or diag1[row+j] or diag2[row-j+N-1]):
            col[j] = diag1[row+j] = diag2[row-j+N-1] = 1
            backtrack(row + 1)
            col[j] = diag1[row+j] = diag2[row-j+N-1] = 0

backtrack()
print(cnt)
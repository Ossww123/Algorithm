N, M = map(int, input().split()) # 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
arr = [0 for _ in range(M)]
used = [0 for _ in range(N+1)]

def backtracking(idx):
    if idx == M:
        print(' '.join(map(str, arr)))
        return

    for i in range(1, N+1):
        if used[i] == 0:
            arr[idx] = i
            used[i] = 1
            backtracking(idx + 1)
            used[i] = 0

backtracking(0)

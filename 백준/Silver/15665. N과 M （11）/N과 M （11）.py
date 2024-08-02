N, M = map(int, input().split())
lst = sorted(set(map(int, input().split())))
N = len(lst)
temp = []

def backtrack():
    if len(temp) == M:
        print(*temp)
        return

    for i in range(N):
        temp.append(lst[i])
        backtrack()
        temp.pop()

backtrack()

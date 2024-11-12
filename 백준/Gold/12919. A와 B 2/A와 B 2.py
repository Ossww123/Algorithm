def solve(idx, str):
    global answer
    if (str not in T and str[::-1] not in T):
        return
    if idx == len(T):
        if str == T:
            answer = 1
        return

    solve(idx+1, str+'A')
    solve(idx+1, (str+'B')[::-1])

S = input()
T = input()
answer = 0
solve(len(S), S)

print(answer)
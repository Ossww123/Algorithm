N = int(input())
p_n = 'O'.join('I' * (N + 1))
length = 2*N + 1

M = int(input())
S = input()

result = 0

for idx in range(M - 2 * N):
    if S[idx:idx + length] == p_n:
        result += 1

print(result)
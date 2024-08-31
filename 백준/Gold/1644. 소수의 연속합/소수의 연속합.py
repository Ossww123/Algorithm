def sieve_of_eratosthenes(N):
    # N까지의 소수를 구하기 위한 배열을 생성하고 초기화
    is_prime = [True] * (N + 1)
    p = 2

    # 소수가 아닌 수를 False로 마킹
    while p * p <= N:
        # is_prime[p]가 True인 경우에만 해당 숫자를 소수로 처리
        if is_prime[p]:
            # p의 배수들을 소수가 아니라고 마킹
            for i in range(p * p, N + 1, p):
                is_prime[i] = False
        p += 1

    # True로 남은 숫자들이 소수이므로, 이를 리스트로 반환
    prime_numbers = [p for p in range(2, N + 1) if is_prime[p]]
    return prime_numbers


# 사용 예시
N = int(input())
pri_nums = sieve_of_eratosthenes(N)

s = e = 0
aaa = pri_nums[0] if pri_nums else 0  # pri_nums가 비어있지 않을 경우 첫 번째 소수로 초기화
cnt = 0
M = len(pri_nums)

while e < M:
    if aaa < N:
        e += 1
        if e < M:
            aaa += pri_nums[e]
    elif aaa > N:
        aaa -= pri_nums[s]
        s += 1
    else:  # aaa == N
        cnt += 1
        aaa -= pri_nums[s]
        s += 1

print(cnt)


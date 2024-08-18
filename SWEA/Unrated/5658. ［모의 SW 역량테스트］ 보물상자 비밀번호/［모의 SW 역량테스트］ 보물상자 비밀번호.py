import heapq
dict_16 = {'A' : 10,
           'B' : 11,
           'C' : 12,
           'D' : 13,
           'E' : 14,
           'F' : 15}
T = int(input())

for tc in range(1, T+1):
    N, K = map(int, input().split())
    lst = input()
    result = []

    for _ in range(N//4):
        for i in range(4):
            num = lst[N//4*i : N//4*(i+1)]

            changed_num = 0
            for j in range(N//4):
                if num[j].isdigit():
                    changed_num += int(num[j]) * (16**(N//4 - 1 - j))
                else:
                    changed_num += dict_16[num[j]] * (16 ** (N // 4 - 1 - j))

            if -changed_num not in result:
                heapq.heappush(result, -changed_num)
        lst = lst[1:] + lst[0]

    for _ in range(K):
        a = -heapq.heappop(result)

    print(f'#{tc} {a}')
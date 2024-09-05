# 충격 조건 충족하는지. changed에 A또는B인지, 어느 열을 변화시켰는지 저장하는 2*D 비트마스크
def check(changed):
    for col in range(W):
        cnt = [0, 0]

        for row in range(D):
            current = film[row][col] if (changed & (1 << row)) == 0 else (changed >> (D + row)) & 1
            cnt[current] += 1
            cnt[1 - current] = 0

            # 연속으로 K번 나오면 통과
            if cnt[0] == K or cnt[1] == K:
                break
        else:
            return False

    return True


def solve(changed=0, cnt=0):
    global result

    # if cnt >= result:
    #     return
    

    if check(changed):
        result = min(result, cnt)
        return

    visited.add(changed)

    for row in range(D):
        if (changed & (1 << row)) != 0:
            continue

        for type_ab in [0, 1]:

            new_changed = changed | (1 << row) | (type_ab << (D + row))

            if new_changed in visited:
                continue

            if cnt + 1 < result:
                solve(new_changed, cnt + 1)


T = int(input())

for tc in range(1, T + 1):
    D, W, K = map(int, input().split())
    film = [list(map(int, input().split())) for _ in range(D)]

    result = K
    visited = set()

    solve()
    print(f'#{tc} {result}')
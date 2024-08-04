T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    lines = []
    for _ in range(N):
        a, b = map(int, input().split())
        lines.append((a,b))

    # 두 선이 교차되면 + 1
    cnt = 0
    for i in range(N-1):
        for j in range(i, N):
            if (lines[i][0] > lines[j][0] and lines[i][1] < lines[j][1]) or \
                (lines[i][0] < lines[j][0] and lines[i][1] > lines[j][1]):
                cnt += 1
    print(f'#{tc} {cnt}')



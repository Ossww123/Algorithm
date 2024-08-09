N = int(input())

arr = [list(map(int, input().split())) for _ in range(N)]

dp_max = arr[0][:]
dp_min = arr[0][:]

for y in range(1, N):
    new_dp_max = [0] * 3
    new_dp_min = [0] * 3

    for x in range(3):
        dummy_lst_max = []
        dummy_lst_min = []

        if x - 1 >= 0:
            dummy_lst_max.append(dp_max[x - 1])
            dummy_lst_min.append(dp_min[x - 1])
        dummy_lst_max.append(dp_max[x])
        dummy_lst_min.append(dp_min[x])
        if x + 1 < 3:
            dummy_lst_max.append(dp_max[x + 1])
            dummy_lst_min.append(dp_min[x + 1])

        new_dp_max[x] = max(dummy_lst_max) + arr[y][x]
        new_dp_min[x] = min(dummy_lst_min) + arr[y][x]

    dp_max = new_dp_max
    dp_min = new_dp_min

print(max(dp_max), min(dp_min))

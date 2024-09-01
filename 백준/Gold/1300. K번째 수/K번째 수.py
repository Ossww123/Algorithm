def count_less_equal(x, N):
    count = 0
    for i in range(1, N + 1):
        count += min(x // i, N)
    return count


def find_kth_smallest(N, k):
    left, right = 1, N * N

    while left < right:
        mid = (left + right) // 2
        count = count_less_equal(mid, N)

        if count < k:
            left = mid + 1
        else:
            right = mid

    return left


N = int(input())
k = int(input())

result = find_kth_smallest(N, k)
print(result)
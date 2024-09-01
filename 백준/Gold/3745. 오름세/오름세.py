from bisect import bisect_left

def find_lis(arr):
    n = len(arr)
    # dp[i]는 길이 i+1인 증가 부분 수열의 마지막 원소 중 가장 작은 값
    dp = []
    # 각 원소의 LIS에서의 이전 원소 인덱스
    prev = [-1] * n
    # LIS의 길이별로 가장 작은 마지막 원소의 인덱스
    last_indices = []

    for i, num in enumerate(arr):
        if not dp or num > dp[-1]:
            if dp:
                prev[i] = last_indices[len(dp) - 1]
            dp.append(num)
            last_indices.append(i)
        else:
            pos = bisect_left(dp, num)
            dp[pos] = num
            last_indices[pos] = i
            if pos > 0:
                prev[i] = last_indices[pos - 1]

    # LIS 구성
    lis = []
    if dp:
        pos = last_indices[-1]
        while pos != -1:
            lis.append(arr[pos])
            pos = prev[pos]

    return lis[::-1]  # 역순으로 반환

while True:
    try:
        N = int(input())
        lst = list(map(int, input().split()))

        lis = find_lis(lst)
        print(len(lis))
    except EOFError:
        break

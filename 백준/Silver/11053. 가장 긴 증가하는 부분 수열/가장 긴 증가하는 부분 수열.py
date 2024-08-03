N = int(input())
nums = list(map(int, input().split()))
nums_cnt = [0] * N
nums_cnt[0] = 1

for i in range(1, N):
    max_cnt = 0
    for j in range(i):
        if nums[j] < nums[i]:
            max_cnt = max(max_cnt, nums_cnt[j])
    nums_cnt[i] = max_cnt + 1

print(max(nums_cnt))
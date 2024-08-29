# 집의 개수 N, 설치할 공유기의 개수 C
N, C = map(int,input().split())

# 집의 좌표 (정렬)
x_axis = [int(input()) for _ in range(N)]
x_axis.sort()

# 이분탐색의 범위와 left, right
distance = max(x_axis) - min(x_axis)
left = 1
right = distance // (C-1)


# 이분탐색 함수
def install_iptime(dis):
    cnt = 1
    curr = x_axis[0]
    for home_idx in range(1,N):
        if x_axis[home_idx] - curr >= dis:
            cnt += 1
            curr = x_axis[home_idx]

    # if cnt >= C:
    #     return True
    # else:
    #     return False
    
    # 멋있게 짜기
    return cnt >= C

# 이분탐색 시작!
while left != right:
    mid = (left + right + 1) // 2
    if install_iptime(mid):
        left = mid
    else:
        right = mid - 1

print(left)
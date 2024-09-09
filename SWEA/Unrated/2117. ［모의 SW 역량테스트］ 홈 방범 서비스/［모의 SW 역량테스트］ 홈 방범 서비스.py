def create_mask(K):
    mask = [[0] * (2*K-1) for _ in range((2*K-1))]
    for i in range((2*K-1)):
        for j in range((2*K-1)):
            if abs(K-1-i) + abs(K-1-j) < K:
                mask[i][j] = 1
 
    return mask
 
 
def manage_cost(k):
    return k*k + (k-1)*(k-1)
 
 
def cal_max_size(house_num, M):
    temp = house_num * M
    size = 0
    while True:
        if manage_cost(size + 1) > temp:
            break
        size += 1
 
    return size
 
 
T = int(input())
for tc in range(1, T+1):
    N, M = map(int,input().split())
    city_map = [list(map(int,input().split())) for _ in range(N)]
 
    house_num = 0
    for i in range(N):
        for j in range(N):
            if city_map[i][j]:
                house_num += 1
 
    max_size = cal_max_size(house_num, M)
 
    K = 1
    max_value = 0
    while K <= max_size:
        mask = create_mask(K)
 
        for y in range(N):
            for x in range(N):
                cnt = 0
                for maskY in range(-(K-1), K):
                    for maskX in range(-(K-1), K):
                        if y+maskY < 0 or y+maskY >= N or x+maskX < 0 or x+maskX >= N:
                            continue
                        if city_map[y+maskY][x+maskX] & mask[(K-1) + maskY][(K-1) + maskX]:
                            cnt += 1
 
                if manage_cost(K) <= cnt*M:
                    max_value = max(max_value, cnt)
 
        K += 1
 
    print(f'#{tc} {max_value}')
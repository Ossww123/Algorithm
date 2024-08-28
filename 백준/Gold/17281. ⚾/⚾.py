from collections import deque
from itertools import permutations

# 결과 저장할 값
max_value = -1

def play_baseball(order):
    score = 0
    now = 0
    for play_num in range(N):  # N회 실시
        current_map = 0  # 0이면 빔, 1이면 주자있음
        out_cnt = 0

        while out_cnt < 3:

            current_man = order[now]  # 이번 순서의 선수
            now += 1
            if now == 9:
                now = 0# 순서 젤 뒤로 넣기
            current_result = mans_conditions[play_num][current_man]  # 이번 선수 결과

            if current_result == 0:  # 아웃이면 땡
                out_cnt += 1
            else:
                current_map = (current_map << 1) + 1
                current_map <<= (current_result - 1)
                temp = current_map>>3

                while temp:
                    score += temp & 1
                    temp >>= 1
                current_map = current_map & 0b111

    return score

def solve():
    global max_value

    for perm in permutations(range(1, 9)):
        order = deque(perm[:3] + (0,) + perm[3:])
        max_value = max(max_value, play_baseball(order))


N = int(input())
mans_conditions = [list(map(int, input().split())) for _ in range(N)]
solve()
print(max_value)
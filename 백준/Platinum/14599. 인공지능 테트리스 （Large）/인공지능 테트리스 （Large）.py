from collections import deque
from pprint import pprint as pp

DY = [0, 0, 1]
DX = [1, -1, 0]

tet = [list(map(int, input())) for _ in range(20)]

blocks = {
    0: [(0, 0), (0, 1), (1, 0), (2, 0)],
    1: [(0, 0), (1, 0), (1, 1), (1, 2)],
    2: [(0, 1), (0, 2), (0, 3), (1, 3)],
    3: [(0, 0), (0, 1), (0, 2), (1, 2)],
    4: [(0, 0), (0, 1), (1, 1), (2, 1)],
    5: [(0, 2), (1, 2), (1, 1), (1, 0)],
    6: [(0, 0), (1, 0), (2, 0), (2, 1)],
    7: [(0, 0), (0, 1), (1, 0), (0, 2)],
    8: [(0, 0), (0, 1), (1, 0), (1, 1)],
    9: [(0, 0), (0, 1), (0, 2), (0, 3)],  # 가로 I
    10: [(0, 0), (1, 0), (2, 0), (3, 0)],  # 세로 I
    11: [(0, 0), (1, 0), (1, 1), (2, 0)],
    12: [(0, 0), (0, 1), (1, 1), (0, 2)],
    13: [(0, 1), (1, 1), (1, 0), (2, 1)],
    14: [(0, 1), (1, 0), (1, 1), (1, 2)],
    15: [(0, 0), (1, 0), (1, 1), (2, 1)],
    16: [(0, 1), (0, 2), (1, 0), (1, 1)],
    17: [(0, 1), (1, 1), (1, 0), (2, 0)],
    18: [(0, 0), (0, 1), (1, 1), (1, 2)],
}


def can_place_block(block_num, y, x):
    """현재 위치에 블록을 놓을 수 있는지 확인"""
    for dy, dx in blocks[block_num]:
        ny, nx = y + dy, x + dx
        if ny < 0 or ny >= 20 or nx < 0 or nx >= 10 or tet[ny][nx] == 1:
            return False
    return True


def remove_row(block_num, axis):
    cnt = 0
    changed_y = set()
    sy, sx = axis

    # 블록 놓기
    for dy, dx in blocks[block_num]:
        ny, nx = sy + dy, sx + dx
        tet[ny][nx] = 1
        changed_y.add(ny)

    # 완성된 줄 확인
    for cy in changed_y:
        if 0 not in tet[cy]:
            cnt += 1

    # 블록 제거 (원상 복구)
    for dy, dx in blocks[block_num]:
        ny, nx = sy + dy, sx + dx
        tet[ny][nx] = 0

    return cnt


max_removed = 0

for i in range(19):
    q = deque()
    q.append((0, 0))
    visited = [[False] * 10 for _ in range(20)]
    visited[0][0] = True
    end_fallens = []

    while q:
        sy, sx = q.popleft()

        for dir in range(3):
            ny = sy + DY[dir]
            nx = sx + DX[dir]

            if ny < 0 or ny >= 20 or nx < 0 or nx >= 10:
                continue
            if visited[ny][nx]:
                continue

            # 현재 위치에 블록을 놓을 수 있는지 확인
            if not can_place_block(i, ny, nx):
                # 아래쪽으로 이동할 때만 최종 위치로 간주
                if dir == 2 and can_place_block(i, sy, sx):
                    end_fallens.append((sy, sx))
                continue

            q.append((ny, nx))
            visited[ny][nx] = True

    for end_fallen in end_fallens:
        cnt = remove_row(i, end_fallen)
        max_removed = max(max_removed, cnt)

print(max_removed)
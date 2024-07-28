from collections import deque

# 가로, 세로, 3X3에 겹치는 숫자 확인
def check_num(sudoku, num_y, num_x, num):
    # 가로
    for x in range(9):
        if num == sudoku[num_y][x]: return False

    # 세로
    for y in range(9):
        if num == sudoku[y][num_x]: return False

    # 3X3 사각형
    start_y = 3 * (num_y // 3)
    start_x = 3 * (num_x // 3)
    for y in range(3):
        for x in range(3):
            if num == sudoku[start_y + y][start_x + x]: return False

    return True

def fill_the_blanks(blanks, sudoku):
    if not blanks:
        return sudoku

    b_y, b_x = blanks.popleft()

    for num in range(1, 10):
        if check_num(sudoku, b_y, b_x, num):
            sudoku[b_y][b_x] = num
            result = fill_the_blanks(blanks, sudoku)
            if result: # 정답
                return result
            sudoku[b_y][b_x] = 0

    blanks.appendleft((b_y, b_x))
    return False

# 입력 받아오기
sudokupan = []
for _ in range(9):
    row = list(map(int, input().split()))
    sudokupan.append(row)

# 빈 칸의 위치
blanks = deque([])
for y in range(9):
    for x in range(9):
        if sudokupan[y][x] == 0:
            blanks.append((y, x))

answer = fill_the_blanks(blanks, sudokupan)

for idx in range(9):
    print(' '.join(map(str, answer[idx])))
import copy
max_value = 0

def push(row):
    new_row = [i for i in row if i != 0]
    new_row += [0] * (len(row) - len(new_row))
    return new_row

def merge(row):
    for i in range(N-1):
        if row[i] == row[i+1]:
            row[i] *= 2
            row[i+1] = 0
    return row

def play_2048(matrix, cnt):
    global max_value
    if cnt == 5:
        for y in range(N):
            for x in range(N):
                max_value = max(max_value, matrix[y][x])
        return

    for command in range(4):
        existing_lst = copy.deepcopy(matrix)
        if command == 0:
            for i in range(N):
                matrix[i] = push(matrix[i])
                matrix[i] = merge(matrix[i])
                matrix[i] = push(matrix[i])
        elif command == 1:
            for i in range(N):
                lst = matrix[i]
                lst.reverse()
                lst = push(lst)
                lst = merge(lst)
                lst = push(lst)
                lst.reverse()
                matrix[i] = lst
        elif command == 2:
            for i in range(N):
                lst = []
                for j in range(N):
                    lst.append(matrix[j][i])
                lst = push(lst)
                lst = merge(lst)
                lst = push(lst)
                for j in range(N):
                    matrix[j][i] = lst[j]
        elif command == 3:
            for i in range(N):
                lst = []
                for j in range(N):
                    lst.append(matrix[j][i])
                lst.reverse()
                lst = push(lst)
                lst = merge(lst)
                lst = push(lst)
                lst.reverse()
                for j in range(N):
                    matrix[j][i] = lst[j]
        cnt += 1
        play_2048(matrix, cnt)
        cnt -= 1
        matrix = copy.deepcopy(existing_lst)

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
play_2048(arr, 0)

print(max_value)
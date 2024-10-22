num = input()
length = len(num)

if length > 1:
    for i in range(1, length):
        left = right = 1

        for index in range(i):
            left *= int(num[index])

        for index in range(i, length):
            right *= int(num[index])

        if left == right:
            print('YES')
            break
    else:
        print('NO')
else:
    print('NO')
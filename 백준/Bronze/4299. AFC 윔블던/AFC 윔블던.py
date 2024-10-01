a, b = map(int, input().split())

x = int((a + b)/2)
y = int((a - b)/2)

if x + y != a or x > y and x - y != b or x < y and y - x != b or x < 0 or y < 0:
    print('-1')
else:
    print(x, y)
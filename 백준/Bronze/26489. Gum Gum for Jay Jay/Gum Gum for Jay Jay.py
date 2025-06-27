count = 0

try:
    while True:
        line = input()
        count += 1
except EOFError:
    print(count)
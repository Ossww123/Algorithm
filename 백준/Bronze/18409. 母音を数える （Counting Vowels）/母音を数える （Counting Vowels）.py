a = int(input())
b = input()
ams = 0

for c in b:
    if c in {'a','e','i','o','u'}:
        ams += 1
print(ams)
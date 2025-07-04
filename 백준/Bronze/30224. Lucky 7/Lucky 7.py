a = input()
b = int(a)
aa = "7" in a
bb = b % 7 == 0
if aa and bb:
    print(3)
elif aa and not bb:
    print(2)
elif not aa and bb:
    print(1)
else:
    print(0)
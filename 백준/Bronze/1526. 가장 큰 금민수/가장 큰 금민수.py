N = int(input())
isAns = False
while not isAns:
    Nstr = str(N)
    for ch in Nstr:
        if (ch != '4'):
            if (ch != '7'):
                N -= 1
                break
    else:
        isAns = True
print(N)
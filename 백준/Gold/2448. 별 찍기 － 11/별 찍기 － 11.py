# 시에르핀스키 삼각형
def sierpinski(n):
    def sierpinski_recursive(size):
        if size == 3:
            return ["  *  ", " * * ", "*****"]

        smaller = sierpinski_recursive(size // 2)
        space = size // 2

        return ([" " * space + line + " " * space for line in smaller] +
                [line + " " + line for line in smaller])

    return sierpinski_recursive(n)


N = int(input())
pattern = sierpinski(N)
for line in pattern:
    print(line)
N = int(input())
form = input()

char_to_num = []
for _ in range(N):
    char_to_num.append(int(input()))

stk = []
for i in form:
    if not i in '+-*/':
        stk.append(char_to_num[ord(i)-ord('A')])
    else:
        num1 = stk.pop()
        num2 = stk.pop()
        if i == '+':
            stk.append(num2+num1)
        elif i == '-':
            stk.append(num2-num1)
        elif i == '*':
            stk.append(num2*num1)
        elif i == '/':
            stk.append(num2/num1)

print(f'{stk[0]:.2f}')
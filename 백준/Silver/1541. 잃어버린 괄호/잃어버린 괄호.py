form = input()
expression = ['']
idx = 0

# 숫자와 연산자를 분리하기 위한 작업
for ch in form:
    if ch.isdigit():
        expression[idx] += ch
    else:
        expression.append(ch)
        expression.append('')
        idx += 2


# 최소값을 찾기 위해 '-' 이후에 나오는 '+'는 '-'로 치환
is_minus = False

for idx in range(1, len(expression), 2):
    if expression[idx] == '-':
        is_minus = True
    if is_minus and expression[idx] == '+':
        expression[idx] = '-'


# 완성된 수식 리스트 계산
sum = int(expression[0])
for idx in range(1, len(expression), 2):
    if expression[idx] == '+':
            sum += int(expression[idx+1])
    else:
        sum -= int(expression[idx + 1])

print(sum)

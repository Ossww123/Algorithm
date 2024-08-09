# ( 6 + 5 * ( 2 - 8 ) / 2 )
# 1. 숫자는 출력
# 2. 연산자는 스택에 넣기
#    2-1 스택에 top이 나보다 우선순위가 낮으면 넣기
#    2-2 낮지 않으면 낮은거 나올때까지 빼고 넣기
# 3. 괄호는 스택에 들어갈 때는 우선순위가 높은데
#     나올때는 우선순위가 낮음(그래야 나중에 나옴)
mid_exp = '(' + input() + ')'
# 우선순위를 알기 위해서
isp = {
    '*': 2,
    '/': 2,
    '+': 1,
    '-': 1,
    '(': 0
}
icp = {
    '*': 2,
    '/': 2,
    '+': 1,
    '-': 1,
    '(': 3
}
# 토큰 하나씩 읽어오기
stack = []
N = len(mid_exp)
result = ''
for i in range(N):
    # mid_exp[i]
    if ord('A') <= ord(mid_exp[i]) <= ord('Z'):  #숫자는 출력
        result += mid_exp[i]
    else: # 연산자는 스택에 넣기
        if mid_exp[i] == ')':   #닫히는 괄호면 출력
            while stack[-1] != '(':
                result += stack.pop()
            stack.pop() # 여는 괄호 삭제
        else:
            if not stack:   # 스택이 비었으면 그냥 넣기
                stack.append(mid_exp[i])
            else:
                if icp[mid_exp[i]] > isp[stack[-1]]:
                    stack.append(mid_exp[i])
                else: # 스택의 top이 나보다 우선순위가 높거나 같으면 빼고 출력
                    while stack and isp[stack[-1]] >= icp[mid_exp[i]]:
                        result += stack.pop()
                    stack.append(mid_exp[i])

print(result)
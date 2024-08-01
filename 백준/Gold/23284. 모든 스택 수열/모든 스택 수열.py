N = int(input())
num_lst = [i for i in range(N, 0, -1)]
stk = []
results = []

def push_pop(numbers, stack, result):
    if not numbers and not stack:
        results.append(result[:])
        return

    for i in range(2):
        if i == 0 and numbers:
            stack.append(numbers.pop())
            push_pop(numbers, stack, result)
            numbers.append(stack.pop())

        elif i == 1 and stack:
            result.append(stack.pop())
            push_pop(numbers, stack, result)
            stack.append(result.pop())

# 시작
push_pop(num_lst, stk, [])

# 결과 정렬
results.sort()

# 정렬된 결과 출력
for res in results:
    print(' '.join(map(str, res)))

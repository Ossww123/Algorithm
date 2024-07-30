from collections import deque

T = int(input())
for tc in range(T):
    rd_func = list(input())
    n = int(input())
    if not n:
        input()
        n_lst = []
    else:
        n_lst = deque(list(map(int, input().strip('[]').split(','))))

    is_reverse = False
    is_error = False

    for func in rd_func:
        if func == 'R':
            is_reverse = not is_reverse
        else:
            if not n_lst:
                is_error = True
                break
            if is_reverse:
                n_lst.pop()
            else:
                n_lst.popleft()

    if is_error:
        print('error')
    else:
        if is_reverse:
            n_lst.reverse()
        result = '[' + ','.join(map(str, n_lst)) + ']'
        print(result)
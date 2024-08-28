def backtrack(result = [], idx=0):
    if idx >= N:
        return

    if idx == (N-1):
        result.append(int(num[idx]))
        if set(result) == set(range(1,maxnum+1)):
            print(' '.join(map(str,result)))
            exit()
        result.pop()
        return

    if idx == (N - 2) and len(result) == maxnum-1:
        result.append(int(num[idx:]))
        if set(result) == set(range(1,maxnum+1)):
            print(' '.join(map(str,result)))
            exit()
        result.pop()
        return

    for i in range(2):
        if i == 0 and int(num[idx]) not in result:
            result.append(int(num[idx]))
            backtrack(result, idx+1)
            result.pop()
        elif i == 1 and int(num[idx:idx+2]) not in result:
            result.append(int(num[idx:idx+2]))
            backtrack(result, idx+2)
            result.pop()

num = str(input())
N = len(num)
if N > 9:
    maxnum = 9 + (N-9)//2
else:
    maxnum = N

backtrack()

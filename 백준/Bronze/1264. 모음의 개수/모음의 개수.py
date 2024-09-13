while True:
    A = input()
    if A == '#':
        break
    lst = ['a','e','i','o','u', 'A', 'E', 'I', 'O', 'U']
    
    cnt = 0
    for ch in A:
        if ch in lst:
            cnt += 1
    
    print(cnt)
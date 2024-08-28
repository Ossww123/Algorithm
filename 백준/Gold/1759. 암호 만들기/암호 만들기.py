def solve(idx=0, result=[]):
    if len(result) == L:
        mnum = jnum = 0
        for i in result:
            if i in m:
                mnum += 1
            else:
                jnum += 1

        if mnum >= 1 and jnum >= 2:
            print(''.join(result))
        return

    for i in range(idx, C):
        result.append(lst[i])
        solve(i+1, result)
        result.pop()


L, C = map(int, input().split())
lst = sorted(list(input().split()))
m = set(['a','e','i','o','u'])

solve()

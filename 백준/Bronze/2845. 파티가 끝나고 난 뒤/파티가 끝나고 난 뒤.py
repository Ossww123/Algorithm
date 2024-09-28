a, b = map(int,input().split())
aa = a * b
bbb = list(map(int,input().split()))
aaaaa = [0,0,0,0,0]
for i in range(5):
    aaaaa[i] = bbb[i] - aa
print(*aaaaa)
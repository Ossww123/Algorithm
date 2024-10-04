import sys
from collections import defaultdict

sys.setrecursionlimit(100000)

def dfs(node, parent):
    max_length1, max_length2 = 0, 0
    for child, weight in tree[node]:
        if child != parent:
            length = dfs(child, node) + weight
            if length > max_length1:
                max_length2 = max_length1
                max_length1 = length
            elif length > max_length2:
                max_length2 = length
    global max_diameter
    max_diameter = max(max_diameter, max_length1 + max_length2)
    return max_length1

V = int(input())
tree = defaultdict(list)

for _ in range(V):
    info = list(map(int, input().split()))
    node = info[0]
    for i in range(1, len(info) - 1, 2):
        if info[i] == -1:
            break
        child, weight = info[i], info[i+1]
        tree[node].append((child, weight))

max_diameter = 0
dfs(1, -1)
print(max_diameter)
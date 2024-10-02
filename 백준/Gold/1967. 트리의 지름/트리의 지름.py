from collections import defaultdict
import heapq
import sys
sys.setrecursionlimit(100000)

n = int(input())
tree = defaultdict(list)
length_node = [0] * (n+1)

for _ in range(n-1):
    u, v, w = map(int,input().split())
    tree[u].append((v,w))

max_heap = []

def solve(root):
    if tree[root]:

        children_num = len(tree[root])
        for i in range(children_num):
            solve(tree[root][i][0])

        w_lst = []
        for i in range(children_num):
            w_lst.append(length_node[tree[root][i][0]] + tree[root][i][1])
        w_lst.sort()
        length_node[root] = w_lst[-1]
        if len(w_lst) == 1:
            heapq.heappush(max_heap, -w_lst[-1])
        else:
            heapq.heappush(max_heap, -(w_lst[-1] + w_lst[-2]))

    else:   # 자식 없으면 그냥 리턴
        return

solve(1)
if max_heap:
    print(-heapq.heappop(max_heap))
else:
    print(0)
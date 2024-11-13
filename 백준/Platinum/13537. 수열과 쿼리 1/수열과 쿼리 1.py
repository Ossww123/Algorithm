import sys
import math

input = sys.stdin.readline
"""
1. 
"""

N = int(input())
A = list(map(int, input().split()))
M = int(input())

left, right, val = 0, 0, 0
node = 2**math.ceil(math.log2(N))
tree = [[] for i in range(node * 2 + 1)]

for i in range(N):
  tree[node + i] = [A[i]]


def init(index):
  if index < node:
    tree[index] = sorted(init(index * 2) + init(index * 2 + 1))
  return tree[index]


def update(start, end, index):
  if start > right or end < left:
    return 0
  if left <= start and end <= right:
    return upperBound(tree[index])

  mid = (start + end) // 2
  return update(start, mid, index * 2) + update(mid + 1, end, index * 2 + 1)


def upperBound(arr):
  l = 0
  r = len(arr)
  while l < r:
    m = (l + r) // 2
    if arr[m] > val: r = m
    else: l = m + 1
  return len(arr) - l


init(1)

for m in range(M):
  left, right, val = map(int, input().split())
  left, right = left, right
  print(update(1, node, 1))
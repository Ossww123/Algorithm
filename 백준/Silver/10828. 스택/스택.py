def push(li, num):
    li.append(num)
    return li

def top(li):
    if not li:
        print(-1)
    else:
        print(li[-1])

def pop(li):
    if not li:
        print(-1)
    else:
        print(li.pop())
    return li

def size(li):
    print(len(li))

def is_empty(li):
    if not li:
        print(1)
    else:
        print(0)

import sys

N = int(input())

stack1 = []

for i in range(N):
    reg = sys.stdin.readline().strip()
    if ' ' in reg:
        a, b = reg.split()
        b = int(b)
        push(stack1, b)
        # print('push')
    elif reg == 'top':
        top(stack1)
        # print('top')
    elif reg == 'size':
        size(stack1)
        # print('size')
    elif reg == 'pop':
        stack1 = pop(stack1)
        # print('pop')
    elif reg == 'empty':
        is_empty(stack1)
        # print('empty')
    


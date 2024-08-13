N = int(input())
heights = [int(input()) for _ in range(N)]
stack = []
max_area = 0

for i in range(N):
    start = i
    while stack and stack[-1][1] > heights[i]:
        index, height = stack.pop()
        area = height * (i - index)
        max_area = max(max_area, area)
        start = index
    stack.append((start, heights[i]))

for i, h in stack:
    area = h * (N - i)
    max_area = max(max_area, area)

print(max_area)
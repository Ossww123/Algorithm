# 입력받기
heights = []
while True:
    input_string = input()
    if input_string == '0':
        break
    heights.append(list(map(int,input_string.split())))

# 테스트케이스
T = len(heights)

for tc in range(T):

    # 필요한 다른 변수들
    stack = []
    max_area = 0
    N = heights[tc][0]
    heights[tc] = heights[tc][1:]

    # i는 출발점에서의 거리
    for i in range(N):
        start = i

        # 스택에 값이 있고 top의 높이가 현재 히스토그램의 높이보다 크다면
        while stack and stack[-1][1] > heights[tc][i]:

            # 스택에 쌓인 히스토그램을 하나씩 빼면서 넓이 계산
            index, height = stack.pop()
            area = height * (i - index)
            max_area = max(max_area, area)
            start = index

        # 현재 히스토그램을 스택에 추가
        stack.append((start, heights[tc][i]))

    # 히스토그램 끝에서의 작업
    for i, h in stack:
        area = h * (N - i)
        max_area = max(max_area, area)

    print(max_area)
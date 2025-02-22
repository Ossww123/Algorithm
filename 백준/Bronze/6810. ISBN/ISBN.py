# 고정된 ISBN 처음 10자리
def isbn_13_sum():
    fixed_digits = [9, 7, 8, 0, 9, 2, 1, 4, 1, 8]
    
    # 마지막 3자리 입력받기
    for _ in range(3):
        digit = int(input())
        fixed_digits.append(digit)

    # 1-3 합계 계산
    total = 0
    for i in range(13):
        if i % 2 == 0:  # 짝수 인덱스 (0부터 시작)는 1을 곱함
            total += fixed_digits[i] * 1
        else:           # 홀수 인덱스는 3을 곱함
            total += fixed_digits[i] * 3

    print(f"The 1-3-sum is {total}")

# 함수 실행
isbn_13_sum()

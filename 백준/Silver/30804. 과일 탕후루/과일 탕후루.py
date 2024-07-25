# 과일의 개수와 탕후루에 꽂힌 리스트를 받습니다.
num_of_fruits = int(input())
tanghuru = list(map(int, input().split()))


# 투포인터를 위한 start, end 값과 결과를 기록할 max_count 변수
s = e = 0
max_count = 0
kinds_of_fruits = {}


# 과일 종류가 3개 이상이면 s를 증가, 그렇지않으면 e증가
while e < num_of_fruits:
    if tanghuru[e] in kinds_of_fruits:
        kinds_of_fruits[tanghuru[e]] += 1
    else:
        kinds_of_fruits[tanghuru[e]] = 1

    # 과일 종류 2개 초과시
    while len(kinds_of_fruits) > 2:
        kinds_of_fruits[tanghuru[s]] -= 1
        if kinds_of_fruits[tanghuru[s]] == 0:
            del kinds_of_fruits[tanghuru[s]]
        s += 1

    if (e - s + 1) > max_count: max_count = e - s + 1

    e += 1

print(max_count)
from pprint import pprint as pp

N = int(input())

# 26개의 알파벳에 대한 카운트를 저장할 수 있도록 변경
str_cnt = [[0] * 26 for _ in range(8)]
for _ in range(N):
    stringnum = input()
    M = len(stringnum)
    for i in range(M):
        str_cnt[i - M + 8][ord(stringnum[i]) - ord('A')] += 1

# pp(str_cnt)

# 26개의 알파벳에 대한 크기를 계산
who_biggest = [[0, i] for i in range(26)]
for ch in range(26):
    for num_pos in range(8):
        who_biggest[ch][0] += str_cnt[num_pos][ch] * (10 ** (8-num_pos))

# 크기 순으로 정렬
who_biggest.sort(key=lambda x:x[0], reverse=True)

# print(who_biggest)

# 상위 10개의 알파벳에 대해서만 숫자 할당
num_dict = {}
for i, temp in enumerate(who_biggest[:10]):
    num_dict[temp[1]] = 9 - i

# print(num_dict)

result = 0
for y in range(8):
    for x in range(26):
        if x in num_dict:  # num_dict에 있는 알파벳에 대해서만 계산
            result += num_dict[x] * (10 ** (8 - y - 1)) * str_cnt[y][x]

print(result)
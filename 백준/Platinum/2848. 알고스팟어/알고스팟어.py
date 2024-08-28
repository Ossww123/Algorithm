from collections import deque

N = int(input())
word_lst = []
used_alphabet = [False] * 26
used_alphabet_count = 0

for _ in range(N):
    temp = input()
    word_lst.append(temp)
    for ch in temp:
        if not used_alphabet[ord(ch) - ord('a')]:
            used_alphabet[ord(ch) - ord('a')] = True
            used_alphabet_count += 1

edges = [[] for _ in range(26)]
indegree = [0] * 26
is_possible = True

for i in range(N - 1):
    word1, word2 = word_lst[i], word_lst[i + 1]
    min_len = min(len(word1), len(word2))

    for j in range(min_len):
        if word1[j] != word2[j]:
            ch1, ch2 = ord(word1[j]) - ord('a'), ord(word2[j]) - ord('a')
            if ch2 not in edges[ch1]:
                edges[ch1].append(ch2)
                indegree[ch2] += 1
            break
    else:
        if len(word1) > len(word2):
            is_possible = False
            break

if is_possible:
    que = deque([i for i in range(26) if used_alphabet[i] and indegree[i] == 0])
    result = []
    is_single_order = True

    for _ in range(used_alphabet_count):
        if not que:
            is_possible = False
            break

        if len(que) > 1:
            is_single_order = False

        curr = que.popleft()
        result.append(chr(curr + ord('a')))

        for next_ch in edges[curr]:
            indegree[next_ch] -= 1
            if indegree[next_ch] == 0:
                que.append(next_ch)

if not is_possible:
    print("!")
elif not is_single_order:
    print("?")
else:
    print(''.join(result))

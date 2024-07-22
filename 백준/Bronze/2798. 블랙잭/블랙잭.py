N, M = map(int, input().split())

card_list = list(map(int, input().split()))

max_value = 3

for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            sum_of_cards = card_list[i] + card_list[j] + card_list[k]
            if sum_of_cards <= M:
                max_value = max(max_value, sum_of_cards)

print(max_value)
                
            

N = int(input())
lst = list(map(int, input().split()))


def binary_search(target):
    left = 0
    right = len(pile_tops)

    while left < right:
        mid = (left + right) // 2
        if pile_tops[mid] < target:
            left = mid + 1
        else:
            right = mid
    return left


pile_tops = []

for num in lst:
    idx = binary_search(num)
    if idx == len(pile_tops):
        pile_tops.append(num)
    else:
        pile_tops[idx] = num

print(len(pile_tops))

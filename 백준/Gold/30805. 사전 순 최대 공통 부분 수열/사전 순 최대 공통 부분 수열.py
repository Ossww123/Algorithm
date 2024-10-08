def lexicographically_largest_common_subsequence(A, B):
    m, n = len(A), len(B)

    # Find all common elements and their indices
    common = []
    for i, a in enumerate(A):
        for j, b in enumerate(B):
            if a == b:
                common.append((a, i, j))

    # Sort common elements in descending order
    common.sort(key=lambda x: x[0], reverse=True)

    result = []
    last_i = last_j = -1

    # Build the lexicographically largest common subsequence
    for num, i, j in common:
        if i > last_i and j > last_j:
            result.append(num)
            last_i, last_j = i, j

    return result[::-1]  # Reverse to get the correct order


# Read input
A = int(input())
A_lst = list(map(int, input().split()))
B = int(input())
B_lst = list(map(int, input().split()))

# Get the result
result = lexicographically_largest_common_subsequence(A_lst, B_lst)
result.reverse()

# Print output
print(len(result))
print(' '.join(map(str, result)))
def print_lcs(s1, s2):
    m, n = len(s1), len(s2)
    lcs = [[0] * (n + 1) for _ in range(m + 1)]

    # Fill the LCS table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                lcs[i][j] = lcs[i - 1][j - 1] + 1
            else:
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1])

    # Retrieve the length of LCS
    lcs_length = lcs[m][n]
    print(lcs_length)

    # Backtrack to find the LCS
    lcs_str = []
    i, j = m, n
    while i > 0 and j > 0:
        if s1[i - 1] == s2[j - 1]:
            lcs_str.append(s1[i - 1])
            i -= 1
            j -= 1
        elif lcs[i - 1][j] >= lcs[i][j - 1]:
            i -= 1
        else:
            j -= 1

    lcs_str.reverse()  # The LCS string was constructed backwards
    if lcs_length:
        print(''.join(lcs_str))

# Read input
s1 = input().strip()
s2 = input().strip()

print_lcs(s1, s2)

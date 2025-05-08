def robinson_crusoe_markings(n):
    v_count = n // 5
    i_count = n % 5
    return 'V' * v_count + 'I' * i_count

day = int(input())
print(robinson_crusoe_markings(day))
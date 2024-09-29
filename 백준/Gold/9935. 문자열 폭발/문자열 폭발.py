def remove_boom(string, boom_str):
    stack = []
    boom_len = len(boom_str)

    for char in string:
        stack.append(char)
        if len(stack) >= boom_len and ''.join(stack[-boom_len:]) == boom_str:
            del stack[-boom_len:]

    return ''.join(stack) if stack else "FRULA"


string = input()
boom_str = input()
result = remove_boom(string, boom_str)
print(result)
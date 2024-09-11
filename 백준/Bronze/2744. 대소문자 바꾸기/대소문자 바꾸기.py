a = input()
r = ''
for ch in a:
    if ch.islower():
        r += ch.upper()
    else:
        r += ch.lower()

print(r)
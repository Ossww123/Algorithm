# 모듈러 곱셈 역원 구하기
def mod_inv(b, m):
    return pow(b, m-2, m)  # b^(m-2) % m

# 모듈러 나눗셈
def mod_div(a, b, m):
    return (a * mod_inv(b, m)) % m

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return abs(a * b) // gcd(a, b)

# 예제 사용
X = 1000000007  # 큰 소수

N = int(input())
up = 0
b, a = map(int, input().split())

for _ in range(N-1):
    nb, na = map(int, input().split())

    c = lcm(b,nb)
    d1 = c // b
    d2 = c // nb

    b = c
    a = a * d1 + na * d2



# 7/3을 mod X에서 계산
result = mod_div(a, b, X)
print(result)  # 7 * 3^(-1) % X

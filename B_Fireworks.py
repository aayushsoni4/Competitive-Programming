from math import gcd

def power(a, b, p):
    if a == 0:
        return 0
    res = 1
    a %= p
    while b > 0:
        if b & 1:
            res = (res * a) % p
        b >>= 1
        a = (a * a) % p
    return res

def lcm(a, b):
    if a == 0 or b == 0:
        return 0
    return (a * b) // gcd(a, b)

def solve():
    n, m, p = map(int, input().split())
    q = lcm(n, m)
    x1 = q
    x2 = q + p
    ans = x2 // n
    ans -= (x1 - 1) // n
    ans += x2 // m
    ans -= (x1 - 1) // m
    print(ans)

testcases = int(input())
for _ in range(testcases):
    solve()

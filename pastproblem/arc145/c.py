mod = 998244353
n = int(input())
res = pow(2, n, mod)
for i in range(n + 2, 2 * n + 1):
    res *= i
    res %= mod
print(res)

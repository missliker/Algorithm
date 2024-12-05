import math

mod = 998244353

def mod_exp(base, exp):
    result = 1
    base = base % mod
    while exp > 0:
        if (exp % 2) == 1:
            result = (result * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return result

n = int(input())
y = pow(2, n - 1)
# print(y)
y = y - n
y = y % mod
print(pow(2, y) % mod)

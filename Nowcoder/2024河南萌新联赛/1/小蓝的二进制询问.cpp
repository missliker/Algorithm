MOD = 998244353

def f(l, r):
    res = 0
    for bit in range(64):
        step = 1 << (bit + 1)
        full_cycles = (r + 1) // step - l // step
        ones_in_full_cycles = full_cycles * (1 << bit)

        remainder_r = (r + 1) % step
        remainder_l = l % step
        ones_in_remainder = max(0, remainder_r - (1 << bit)) - max(0, remainder_l - (1 << bit))

        res += ones_in_full_cycles + ones_in_remainder
        res %= MOD

    return res

if __name__ == "__main__":
        t = int(input().strip())
    results = []

    for _ in range(t):
        l, r = map(int, input().strip().split())
        results.append(f(l, r))

    for result in results:
        print(result)
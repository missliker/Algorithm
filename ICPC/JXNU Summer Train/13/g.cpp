#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 mod = 998244353;
i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; a = a * a % mod, b >>= 1) {
        if (b & 1) res = (res * a) % mod;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    cout << power(2LL, (power(2LL, n - 1) - n + mod) % mod) << '\n';

    return 0;
}
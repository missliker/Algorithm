#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
constexpr i64 mod = 998244353;
vector<i64> F(3E5 + 1), inF(3E5 + 1);

i64 power(i64 a, i64 n, i64 mo) {
    i64 res = 1 % mo, t = a;
    while (n) {
        if (n & 1) res = res * t % mo;
        t = t * t % mo;
        n >>= 1;
    }
    return res % mo;
}

i64 C(int n, int m) {
    if (m > n) return 0LL;
    return 1LL * F[n] * inF[m] % mod * inF[n - m] % mod;
}

i64 A(int n, int m) {
    if (m > n) return 0LL;
    return 1LL * C(n, m) * F[m] % mod;
}

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> a(n);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > i + 1 or (i and a[i] < a[i - 1])) ok = false;
    }
    if (a.back() != n or !ok) {
        cout << "0\n";
        return;
    }

    i64 lst = 0, cnt = 0, mor = 0, ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != lst) {
            i64 ned = a[i] - lst - 1;
            mor += cnt;
            cnt = 0;
            ans = ans * A(mor, ned) % mod;
            mor -= ned;
        } else {
            cnt++;
        }
        lst = a[i];
    }
    cnt += mor;
    ans = ans * A(cnt, cnt) % mod;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    F[0] = inF[0] = 1LL;
    for (int i = 1; i <= 3E5; i++) {
        F[i] = F[i - 1] * i % mod;
        inF[i] = inF[i - 1] * power(i, mod - 2, mod) % mod;
    }

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
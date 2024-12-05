#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 exgcd(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void Solution(int T) {
    i64 n, m, a, b, k;
    cin >> n >> m >> a >> b >> k;
    i64 x0, y0, g = exgcd(a, b, x0, y0);
    if (k % g != 0) {
        cout << n + m << '\n';
        return;
    }

    x0 *= k / g, y0 *= k / g;
    a /= g, b /= g;

    auto ceil_div = [&](i64 x, i64 y) -> i64 {
        return -(-x / y);
    };

    auto floor_div = [&](i64 x, i64 y) -> i64 {
        return x / y;
    };

    i64 ans = n + m;
    i64 min_e = max(ceil_div(-x0, b), ceil_div(y0 - m, a));
    i64 max_e = min(floor_div(n - x0, b), floor_div(y0, a));
    for (i64 e = min_e; e <= max_e; e++) {
        i64 x = x0 + e * b, y = y0 - e * a;
        if (x >= 0 and x <= n and y >= 0 and y <= m) {
            // cerr << x << ' ' << y << endl;
            i64 cnt = min((x ? n / x : n), (y ? m / y : m));
            ans = min(ans, n + m - (x + y) * cnt);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
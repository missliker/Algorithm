#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    i64 k, x, y;
    cin >> k >> x >> y;
    if (k == 1) {
        cout << x + y << '\n';
        return;
    }
    if (k & 1) {
        i64 L = y * 2 / (k - 1);
        i64 ans = 0;
        if (L <= x) {
            ans += L;
            x -= L;
            y -= L * (k - 1) / 2;
            if (x >= k - y * 2) {
                ans++;
                x -= k - y * 2;
            }
            ans += x / k;
        } else {
            ans += x;
            y -= x * (k - 1) / 2;
            ans += y * 2 / (k + 1);
        }
        cout << ans << '\n';
    } else {
        cout << (2LL * y + x) / k << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
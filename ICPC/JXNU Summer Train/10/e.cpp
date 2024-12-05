#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    vector a(n, 0), b(n, 0), w(n, 0), v(0, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> w[i];
        b[i]++;
        v.emplace_back(a[i]);
        v.emplace_back(b[i]);
    }
    ranges::sort(v);
    v.erase(unique(v.begin(), v.end()), v.end());

    vector d(n << 1, 0LL), xd(n << 1, 0LL);
    for (int i = 0; i < n; i++) {
        int l = ranges::lower_bound(v, a[i]) - begin(v) + 1;
        int r = ranges::lower_bound(v, b[i]) - begin(v) + 1;
        d[l]++, d[r]--;
        xd[l] ^= w[i], xd[r] ^= w[i];
    }

    const i64 INF = 1E18 + 10;
    i64 ans = -INF;
    for (int i = 1; i <= v.size(); i++) {
        d[i] += d[i - 1];
        xd[i] ^= xd[i - 1];
        if (d[i] >= k) ans = max(ans, xd[i]);
    }

    if (ans == -INF) ans = -1;
    cout << ans << '\n';

    return 0;
}
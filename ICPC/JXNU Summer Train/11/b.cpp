#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    const int INF = 1E9;
    int mn = INF;
    for (int i = n; i >= 1; i--) {
        if (c[i] < mn) {
            mn = c[i];
        } else {
            c[i] = INF;
        }
    }

    int ans = 0, cost = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] == INF or i - cost < c[i]) continue;
        int cnt = (i - cost) / c[i];
        ans += cnt;
        cost += cnt * c[i];
    }
    cout << ans << '\n';

    return 0;
}
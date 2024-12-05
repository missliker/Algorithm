#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        g[u].insert(v);
    }

    vector<int> R(n + 1, n);
    for (int i = n - 1; i >= 1; i--) {
        int m = i + g[i].size() + 1;
        R[i] = min(R[i + 1], m);
        for (int j = i + 1; j <= min(n, m); j++) {
            if (g[i].find(j) != g[i].end()) continue;
            R[i] = min(R[i], j - 1);
            break;
        }
    }

    i64 ans = 0;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        if (st.find(R[i]) != st.end()) continue;
        st.insert(R[i]);
        ans += 1LL * (R[i] - i + 1) * (R[i] - i) / 2;
    }
    cout << ans + n << '\n';

    return 0;
}
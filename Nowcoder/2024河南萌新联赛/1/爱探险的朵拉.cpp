#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    vector<set<int>> f(n + 1);
    auto dfs = [&](auto self, int u, int res) -> void {
        ans = max(ans, res);
        if (f[u].find(a[u]) != f[u].end()) return;
        f[u].insert(a[u]);
        f[a[u]].insert(u);
        self(self, a[u], res + 1);
    };
    int final = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i].size()) continue;
        ans = 0;
        dfs(dfs, i, 0);
        final = max(final, int(f[i].size()));
    }
    cout << final << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> u(m + 1), v(m + 1);
    for (int i = 1; i <= m; i++) cin >> u[i] >> v[i];
    int ans = n;
    function<void(int)> dfs = [&](int cnt) {
        if (cnt == m + 1) {
            vector<int> p(n + 1);
            iota(p.begin(), p.end(), 0);
            sort(p.begin() + 1, p.end(), [&](int i, int j) { return a[i] > a[j]; });
            int now = n;
            for (int i = 1; i <= n; i++) {
                if (p[i] == 1) now = i;
            }
            ans = min(ans, now);
            return;
        }

        a[u[cnt]] += 3;
        dfs(cnt + 1);
        a[u[cnt]] -= 3;

        a[v[cnt]] += 3;
        dfs(cnt + 1);
        a[v[cnt]] -= 3;

        a[u[cnt]] += 1;
        a[v[cnt]] += 1;
        dfs(cnt + 1);
        a[u[cnt]] -= 1;
        a[v[cnt]] -= 1;
    };
    dfs(1);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}


#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<vector<int>> adj;
constexpr int N = 1E5 + 10;
int a[N], in[N], p[N], cnt[N];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    cnt[u] += cnt[v];
    p[v] = u;
    return true;
}

void Solution(int T) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
        cnt[i] = 1;
    }
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (a[u] * 2 >= a[v] and a[v] * 2 >= a[u]) {
            merge(u, v);
            continue;
        }
        if (a[u] * 2 >= a[v]) {
            adj[v].emplace_back(u);
        } else if (a[v] * 2 >= a[u]) {
            adj[u].emplace_back(v);
        }
    }

    for (int i = 1; i <= n; i++) in[i] = 0;
    for (int i = 1; i <= n; i++) {
        int u = i;
        for (auto v : adj[u]) {
            u = find(u), v = find(v);
            if (u == v) continue;
            in[v]++;
        }
    }

    int ans = 0, tree = 0;
    for (int u = 1; u <= n; u++) {
        if (u != find(u) or in[u]) continue;
        tree++;
        ans += cnt[u];
    }
    if (tree > 1) ans = 0;
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
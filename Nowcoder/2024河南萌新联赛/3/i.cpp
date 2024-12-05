#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
ostream& operator<<(ostream& os, Pair n) {
    string a, b, s, flag;
    if (n.first < 0) flag = "-", n.first *= -1;
    while (n.first) {
        a += '0' + n.first % 10;
        n.first /= 10;
    }
    a += flag;
    reverse(a.begin(), a.end());
    flag = string("");
    if (n.second < 0) flag = "-", n.second *= -1;
    while (n.second) {
        b += '0' + n.second % 10;
        n.second /= 10;
    }
    b += flag;
    reverse(b.begin(), b.end());
    s = "[" + a + ", " + b + "]\n";
    return os << s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, k;
    cin >> n >> m >> k;
    vector adj(n + 1, vector<Pair>()), adj2(n + 1, vector<Pair>());
    for (int i = 0; i < m; i++) {
        i64 a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d == 1) {
            adj[a].emplace_back(b, c);
            adj[b].emplace_back(a, c);
        }
        adj2[a].emplace_back(b, c);
        adj2[b].emplace_back(a, c);
    }

    const i64 INF = 1E18 + 10;
    auto dij = [&](int n, int s) {
        vector<i64> dist(n + 1, INF);
        vector<int> st(n + 1);
        dist[s] = 0LL;
        priority_queue<Pair, vector<Pair>, greater<Pair>> heap;
        heap.push({0LL, s});
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            i64 u = t.second, dis = t.first;

            if (st[u]) continue;
            st[u] = true;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    heap.push({dist[v], v});
                }
            }
        }

        return dist;
    };
    auto dis = dij(n, 1);
    i64 ans = dis[n];
    i64 ans2 = dis[k];

    auto dij2 = [&](int n, int s) {
        vector<i64> dist(n + 1, INF);
        vector<int> st(n + 1);
        dist[s] = 0LL;
        priority_queue<Pair, vector<Pair>, greater<Pair>> heap;
        heap.push({0LL, s});
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            i64 u = t.second, dis = t.first;

            if (st[u]) continue;
            st[u] = true;

            for (auto [v, w] : adj2[u]) {
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    heap.push({dist[v], v});
                }
            }
        }

        return dist;
    };
    auto dis2 = dij2(n, k);
    ans2 += dis2[n];
    ans = min(ans, ans2);
    if (ans >= INF) ans = -1;
    cout << ans << '\n';

    return 0;
}
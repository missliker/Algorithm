#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
constexpr i64 INF = 1E18 + 10;
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

    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    vector<vector<Pair>> adj(N + 1);
    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

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
                if (dist[v] > dis + w + A[v]) {
                    dist[v] = dis + w + A[v];
                    heap.push({dist[v], v});
                }
            }
        }
        return dist;
    };
    auto dis = dij(N, 1);
    for (int i = 2; i <= N; i++) cout << dis[i] + A[1] << " \n"[i == N];

    return 0;
}
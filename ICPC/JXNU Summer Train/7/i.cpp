#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, char>;

void Solution(int T) {
    int n;
    cin >> n;
    vector adj(n + 1, vector<Pair>());
    for (int i = 1; i < n; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    int cnt = 0, ans = 0;
    for (int u = 1; u <= n; u++) {
        map<char, vector<int>> mp;
        for (auto& [v, c] : adj[u]) {
            mp[c].emplace_back(v);
        }
        cout << "c: " << mp.size() << endl;
        auto [c, vec] = *mp.begin();
        cout << "vec: " << vec.size() << endl;
        if (mp.size() == 1 and vec.size() > 1) {
            cnt++;
            ans = vec.size();
        }
    }
    if (cnt == 1) {
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
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
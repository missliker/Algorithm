#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

vector<vector<int>> g(7);
struct node {
    string sta;
    i64 x;
};

void solve(int T) {
    string s, fi;
    cin >> s >> fi;
    if (s == fi) {
        cout << "0\n";
        return;
    }
    int n = s.size();
    s = " " + s;
    fi = " " + fi;
    auto onetap = [&](int x, string str) {
        string res = str;
        if (res[x] == '0') res[x] = '1';
        else res[x] = '0';
        for (auto y : g[x]) {
            if (str[y] == '0') res[y] = '1';
            else res[y] = '0';
        }
        return res;
    };
    map<string, bool> vis;
    vis[s] = true;
    queue<node> bfs;
    bfs.push(node{s, 0});
    i64 ans = 1e18;
    while (bfs.size()) {
        auto [sta, x] = bfs.front();
        bfs.pop();
        if (sta == fi) ans = min(ans, x);
        for (int i = 1; i <= n; i++) {
            string str = sta;
            string res = onetap(i, str);
            if (!vis.count(res) or vis[res] == false) {
                vis[res] = true;
                bfs.push(node{res, x + 1});
            }
        }
    }
    if (ans == 1e18) ans = -1;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    g[1].push_back(2);
    g[1].push_back(5);
    g[1].push_back(6);
    g[2].push_back(1);
    g[2].push_back(3);
    g[3].push_back(2);
    g[3].push_back(4);
    g[3].push_back(6);
    g[4].push_back(3);
    g[4].push_back(5);
    g[4].push_back(6);
    g[5].push_back(4);
    g[5].push_back(1);
    g[6].push_back(1);
    g[6].push_back(3);
    g[6].push_back(4);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}

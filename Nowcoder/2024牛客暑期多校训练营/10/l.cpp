#include <bits/stdc++.h>
using namespace std;
using i64 = long long;



void Solution(int T) {
    int n, m;
    cin >> n >> m;
    string s[m];
    vector<int> op(m);
    vector<set<string>> st(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> op[i];

        auto dfs = [&](auto self, int u, string res) -> void {
            if (u == op[i]) {
                st[i].insert(res);
                return;
            }
            for (int len = 1; len <= n; len++) {
                for (int l = 0; l + len - 1 < n; l++) {
                    int r = l + len - 1;
                    string a = res, b = res;
                    for (int j = l; j <= r; j++) {
                        int x = a[j] - '0', k = op[i];
                        a[j] = (x + 1) % 10 + '0';
                        b[j] = (x + 9) % 10 + '0';
                    }
                    self(self, u + 1, a);
                    self(self, u + 1, b);
                }
            }
        };
        dfs(dfs, 0, s[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     for (auto& have : st[i]) {
    //         cout << have << ' ';
    //     }
    //     cout << endl;
    // }

    map<string, int> cnt;
    for (int i = 0; i < m; i++) {
    	for (auto& x : st[i]) {
    		cnt[x]++;
    	}
    }

    set<string> ans;
    for (auto& [x, y] : cnt) {
    	if (y == m) {
    		ans.insert(x);
    	}
    }

    // set<string> ans = st[0];
    // for (int i = 0; i < m; i++) {
    //     set<string> wait;
    //     for (auto& have : ans) {
    //         if (st[i].find(have) == st[i].end()) {
    //             wait.insert(have);
    //         }
    //     }
    //     for (auto& del : wait) {
    //         ans.erase(del);
    //     }
    // }

    // // for (auto& x : ans) {
    // //     cout << x << '\n';
    // // }

    if (ans.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        if (ans.size() == 1) {
            cout << *ans.begin() << '\n';
        } else {
            cout << "MANY\n";
        }
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
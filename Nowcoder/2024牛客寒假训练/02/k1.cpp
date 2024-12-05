#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    i64 n, y;
    string s, str = "";
    cin >> n >> s >> y;
    map<char, char> st;
    for (auto c : s) {
        if (c >= 'a' and c <= 'd') st[c] = '#';
    }
    i64 ans = 0;
    vector<int> vis(10);
    auto dfs = [&](auto self, int i) {
        if (i == n) {
            int x = stoi(str, 0, 10);
            if (str == "0") ans += 1;
            if(str[0] == '0') return;
            if (x % 8 == 0 and x <= y) ans += 1;
            return;
        }
        if (s[i] >= '0' and s[i] <= '9') {
            str += s[i];
            self(self, i + 1);
        } else if (s[i] >= 'a' and s[i] <= 'd') {
            if (st[s[i]] == '#') {
                for (char j = '0'; j <= '9'; j++) {
                    if (!vis[j - '0']) {
                        vis[j - '0'] = 1;
                        string tmp = str;
                        str += j;
                        st[s[i]] = j;
                        self(self, i + 1);
                        st[s[i]] = '#';
                        str = tmp;
                        vis[j - '0'] = 0;
                    }
                }
            } else {
                str += st[s[i]];
                self(self, i + 1);
            }
        } else {
            for (char j = '0'; j <= '9'; j++) {
                string tmp = str;
                str += j;
                self(self, i + 1);
                str = tmp;
            }
        }
    };
    dfs(dfs, 0);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}

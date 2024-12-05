#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
constexpr i64 mod = 1e9 + 7;

void solve(int T) {
    int n;
    string s, str = "";
    int y;
    cin >> n >> s >> y;
    map<char, char> st;
    for (auto c : s) {
        if (c >= 'a' and c <= 'z') st[c] = '#';
    }
    i64 ans = 0;
    vector<int> vis(10);
    auto dfs = [&](auto self, int i) {
        if (i == n) {
            int now = stoi(str);
            if (str == "0") ans += 1;
            if (str[0] == '0') return;
            if (now % 8 == 0 and now <= y) ans += 1;
            return;
        }
        if (s[i] >= '0' and s[i] <= '9') {
            str += s[i];
            self(self, i + 1);
        } else if (s[i] >= 'a' and s[i] <= 'd') {
            if (st[s[i]] == '#') {
                for (char j = '0'; j <= '9'; j++) {
                    if (!vis[j - '0']) {
                        string tmp = str;
                        vis[j - '0'] = 1;
                        st[s[i]] = j;
                        str += j;
                        self(self, i + 1);
                        str = tmp;
                        st[s[i]] = '#';
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

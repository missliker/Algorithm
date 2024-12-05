#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int n = 10;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m += a[i];
    }

    string ans = string(m, '9');
    auto dfs = [&](auto self, int u, string res) -> void {
        if (u == m) {
            if (res.front() != '0') ans = min(ans, res);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] and (res.empty() or i != (res.back() - '0'))) {
                a[i]--;
                self(self, u + 1, res + char('0' + i));
                a[i]++;
            }
        }
    };
    dfs(dfs, 0, string(""));
    // debug(ans);
    if (ans == string(m, '9')) {
        ans = "-1";
    }
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
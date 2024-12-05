#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...) (void)0
#endif
using i64 = int64_t;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti += 1) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        vector<vector<int>> p(16);
        for (int i = 1; i <= n; i += 1) {
            string s;
            cin >> s;
            for (int j = 0; j < 4; j += 1)
                if (s.find("BGRY"[j]) != string::npos) a[i] |= 1 << j;
            p[a[i]].push_back(i);
        }
        debug(a);
        for (int i = 0, x, y; i < q; i += 1) {
            cin >> x >> y;
            if (x > y) swap(x, y);
            if (a[x] & a[y]) {
                cout << y - x << "\n";
                continue;
            }
            constexpr int inf = numeric_limits<int>::max();
            int ans = inf;
            for (int j = 0; j < 16; j += 1) {
                if (not p[j].empty() and (j & a[x]) and (j & a[y])) {
                    auto it = ranges::lower_bound(p[j], x);
                    if (it != p[j].end()) {
                        if (*it <= y) {
                            ans = y - x;
                        } else {
                            ans = min(ans, 2 * *it - x - y);
                        }
                    }
                    if (it != p[j].begin()) ans = min(ans, x + y - 2 * *prev(it));
                }
            }
            cout << (ans == inf ? -1 : ans) << "\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    set<int> st;
    vector<int> b(n);
    int ans = 0;
    auto dfs = [&](auto self, int u) -> void {
        if (u == n) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += (a[i] == b[i]);
            }
            ans = max(ans, res);
            return;
        }
        if (a[u] == u) {
            st.insert(u);
            b[u] = u;
            self(self, u + 1);
        } else {
            if (st.find(u) == st.end()) {
                st.insert(u);
                b[u] = u;
                self(self, u + 1);
                st.erase(u);
            }
            if (st.find(a[u]) == st.end()) {
                st.insert(a[u]);
                b[u] = a[u];
                self(self, u + 1);
                st.erase(a[u]);
            }
        }
    };
    dfs(dfs, 0);
    if (ans != n) {
        ans = 0;
    }
    cout << ans << '\n';

    return 0;
}
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    set<int> st;
    int ans = 0;
    for (int l = 1, r = l; l <= n; l++) {
        while (r <= n and st.find(a[r]) == st.end()) {
            st.insert(a[r]);
            int Insert = a[r];
            debug(Insert);
            r++;
        }
        ans = max(ans, int(st.size()));
        int l2 = r;
        while (l2 <= n and st.find(a[l2]) != st.end()) {
            l2++;
        }
        set<int> wait;
        for (int r2 = l2; l2 <= n; l2++) {
            r2 = max(r2, l2);
            while (r2 <= n and st.find(a[r2]) == st.end() and wait.find(a[r2]) == wait.end()) {
                int Insert2 = a[r2];
                debug(Insert2);
                wait.insert(a[r2]);
                r2++;
            }
            ans = max(ans, int(st.size()) + int(wait.size()));
            debug(l, r, l2, r2, st, wait);
            if (r2 - l2 >= 1) {
                wait.erase(a[l2]);
                int Erase2 = a[l2];
                debug(Erase2);
            }
        }
        if (r - l >= 1) {
            st.erase(a[l]);
            int Erase = a[l];
            debug(Erase);
        }
    }
    cout << ans << '\n';

    return 0;
}
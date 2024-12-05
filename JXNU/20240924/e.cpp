#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, d, x;
    cin >> n >> d >> x;
    priority_queue<Pair> q;
    vector<int> k(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        q.emplace(c[i], k[i]);
    }

    i64 ans = 0;
    while (d and not q.empty()) {
        int cnt = x;
        vector<Pair> wait;
        while (cnt and not q.empty()) {
            auto [c, k] = q.top();
            q.pop();
            ans += c;
            if (k > 1) {
            	wait.emplace_back(c, k - 1);
            }
            cnt--;
        }
        for (auto& i : wait) {
            q.emplace(i);
        }
        // debug(wait);
        d--;
        // debug(ans);
    }
    cout << ans << '\n';

    return 0;
}
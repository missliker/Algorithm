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

    int n, k;
    cin >> n >> k;
    vector<int> r(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    auto dfs = [&](auto self, int u) -> void {
        if (u == n) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
            }
            if (sum % k == 0) {
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " \n"[i == n - 1];
                }
            }
            return;
        }
        for (int i = 1; i <= r[u]; i++) {
            a[u] = i;
            self(self, u + 1);
        }
    };
    dfs(dfs, 0);

    return 0;
}
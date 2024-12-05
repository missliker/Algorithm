#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

struct Basis {
    Pair w[63] = {};
    int m = 0;

    void assign() {
        for (int i = 0; i < m; i++) {
            w[i] = {0, 0};
        }
        m = 0;
    }

    void insert(Pair x) {
        for (int i = 62; i >= 0; i--) {
            if (x.second >> i & 1) {
                if (not w[i].second) {
                    w[i] = x;
                    if (i + 1 > m) {
                        m = i + 1;
                    }
                    break;
                }
                x.second ^= w[i].second;
            }
        }
    }

    int size() { return m; }
} basis;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<Pair> info(n);
    for (int i = 0; i < n; i++) {
        cin >> info[i].second >> info[i].first;
    }
    sort(info.begin(), info.end(), greater());

    for (int i = 0; i < n; i++) {
        basis.insert(info[i]);
    }

    i64 ans = 0;
    for (int i = 0; i < basis.size(); i++) {
        ans += basis.w[i].first;
    }
    cout << ans << '\n';

    return 0;
}
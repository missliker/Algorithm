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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto b = a;
    int s;
    cin >> s;
    int t = s;
    unordered_set<int> id;
    vector<int> p;
    while (true) {
        int nxt = (t - 1 + k) % n + 1;
        t = nxt;
        if (a[nxt]) {
            a[nxt]--;
            if (a[nxt] == 0) {
                cout << nxt << '\n';
                return 0;
            }
            if (id.find(nxt) == id.end()) {
                id.insert(nxt);
                p.emplace_back(nxt);
            } else {
                break;
            }
        } else {
            cout << nxt << '\n';
            return 0;
        }
    }

    int mn = 1E9 + 10, ans = 0;
    for (auto& i : p) {
        // cout << i << ' ' << b[i] << ' ' << mn << endl;
        if (b[i] < mn) {
            mn = b[i];
            ans = i;
        }
    }
    cout << ans << '\n';

    return 0;
}
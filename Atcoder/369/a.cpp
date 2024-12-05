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

    int a, b;
    cin >> a >> b;
    set<vector<int>> ans;
    for (int i = -500; i <= 500; i++) {
        vector<int> t{i, a, b};
        sort(t.begin(), t.end());
        if (t[1] - t[0] == t[2] - t[1]) {
            ans.insert(t);
        }
    }
    cout << ans.size() << '\n';

    return 0;
}
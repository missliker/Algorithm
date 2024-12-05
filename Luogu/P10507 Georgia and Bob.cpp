#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int n;
    cin >> n;

    vector<int> a(n + 1), b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = n; i >= 1; i--) {
        b.emplace_back(a[i] - a[i - 1] - 1);
    }

    int ans = 0;
    for (int i = 0; i < b.size(); i += 2) {
        ans ^= b[i];
    }
    debug(ans);
    cout << (ans ? "Georgia will win" : "Bob will win") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
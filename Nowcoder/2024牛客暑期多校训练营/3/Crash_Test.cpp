#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, D;
    cin >> n >> D;
    vector<i64> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    i64 ans = h.front();
    for (int i = 0; i < n; i++) {
        ans = gcd(ans, h[i]);
    }
    cout << min(D % ans, ans - D % ans) << '\n';

    return 0;
}
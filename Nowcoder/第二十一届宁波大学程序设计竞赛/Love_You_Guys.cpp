#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 X, Y, a, b;
    cin >> X >> Y >> a >> b;
    i64 mx = X;
    i64 ans = 0;
    while (X >= 0) {
        X = X - (a + b * ans);
        X += Y;
        X = min(X, mx);
        ans++;
    }
    cout << ans << '\n';

    return 0;
}
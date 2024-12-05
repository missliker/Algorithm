#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n + 1);
    i64 s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s ^= a[i];
    }
    i64 ans = s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n / i; j++) {
            ans = max(ans, (s ^ a[i] ^ (a[i] + j)));
            ans = max(ans, (s ^ a[i] ^ (a[i] * j)));
        }
    }
    cout << ans << '\n';

    return 0;
}
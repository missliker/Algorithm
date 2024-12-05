#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, x;
    cin >> n >> x;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] - x;
    }
    i64 sum = a[1], ans = a[1];
    for (int i = 2; i <= n; i++) {
        sum = max(sum + a[i], a[i]);
        ans = max(ans, sum);
    }
    if (ans < 0) ans = 0;
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n + 1);
    i64 ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
        sum += a[i];
    }
    ans += n;
    for (int i = 1; i <= n; i++) ans = max(ans, sum + a[i] * (n - 1));
    cout << ans << '\n';

    return 0;
}
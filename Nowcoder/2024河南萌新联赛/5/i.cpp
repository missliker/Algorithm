#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + c[i - 1];
    }

    i64 ans = 1E18;
    for (int i = 0; i <= 1E6; i++) {
        int a = lower_bound(c.begin(), c.end(), i) - c.begin();
        i64 res = s[n] - s[a] * 2LL + (2LL * a - n) * i;
        ans = min(ans, res + 1);
    }
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(6);

    int n, k;
    cin >> n >> k;
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    for (int i = k; i <= n; i++) {
        double ans = 1.0 * (s[i] - s[i - k]) / k;
        if (ans < 1024) {
            cout << ans << " KiBps\n";
        } else {
            cout << ans / 1024.0 << " MiBps\n";
        }
    }

    return 0;
}
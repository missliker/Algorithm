#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, L, R;
    cin >> n >> L >> R;
    vector<i64> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        h[i] = (h[i] - 1) / 2;
    }

    i64 ned = (n - L - 1) / (R - L) * L;
    for (int i = 0; i < n; i++) {
        ned -= min(h[i], (n - L - 1) / (R - L));
    }
    if (ned <= 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
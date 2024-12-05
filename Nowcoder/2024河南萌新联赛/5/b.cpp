#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n);
    i64 s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    int L, R;
    cin >> L >> R;

    if (s < 1LL * L * n or s > 1LL * R * n) {
        cout << "-1\n";
        return 0;
    }

    i64 sub = 0, add = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < L) {
            sub += L - a[i];
        } else if (a[i] > R) {
            add += a[i] - R;
        }
    }
    cout << max(sub, add) << '\n';

    return 0;
}
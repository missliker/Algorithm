#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;

        auto build = [&](int l, int r) -> void {
            if (l > y or r < x) return;
            if (l >= x and r <= y) {
            }
        };
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
    }

    sort(a.begin(), a.end());
    while (q--) {
        int k;
        cin >> k;
        k--;
        cout << a[k] << '\n';
    }

    return 0;
}
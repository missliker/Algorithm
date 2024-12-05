#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i <= n; i++) a[0] = max(a[0], (a[0] ^ i));
    cout << 1LL * n * a[0] << '\n';

    return 0;
}
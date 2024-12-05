#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(b.begin(), b.end());
    i64 ans = 0;
    for (auto& x : a) {
        auto it = lower_bound(b.begin(), b.end(), x);
        ans += *it;
    }
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    i64 s = 0;
    for (auto& i : a) s += i;
    i64 ans = s / k;
    if (k > s) ans = -1;
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
constexpr i64 mod = 998244353; 

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n;
    cin >> n;
    map<i64, i64> v;
    for (int i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        v[x] += 1;
    }
    i64 ans = 0;
    for (auto [ax, ay] : v) {
        for (auto [bx, by] : v) {
            ans = (ans + gcd(ax, bx) * (__builtin_popcountll(u64(ax)) + __builtin_popcountll(u64(bx))) * ay * by) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (i % 2 == 0 ? 1 : -1) * a[i];
    }

    ans = std::max<i64>(ans - k, n % 2 == 0 ? 0 : a[n - 1]);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
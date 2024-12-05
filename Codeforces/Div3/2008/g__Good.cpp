#include <bits/stdc++.h>

using i64 = long long;

void DAOQI() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        g = std::gcd(a[i], g);
    }
    if (n == 1) {
        std::cout << (k > a[1] ? k : k - 1) << "\n";
        return;
    }
    i64 lst = 0;
    for (int i = 1, j = 0; i <= n; i++, j += g) {
        a[i] = j;
        if (a[i] < lst) break;
        if (a[i] == lst) {
            lst++;
            continue;
        } else {
            int t = a[i] - lst;
            if (t < k) {
                k -= t;
                lst = a[i] + 1;
            } else {
                std::cout << lst + k - 1 << "\n";
                return;
            }
        }
    }
    std::cout << lst + k - 1 << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) DAOQI();
    return 0;
}

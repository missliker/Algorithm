#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), now(n + 1), lst(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lst[i] = now[a[i]];
        now[a[i]] = i;
    }

    i64 ans = 0;
    vector<int> L(n + 1);
    for (int i = 1; i <= n; i++) {
        if (lst[i] == 0) {
            L[i] = max(1, L[i - 1]);
            ans += i - L[i] + 1;
            continue;
        }
        if (i - lst[i] <= k) {
            L[i] = max(1, L[i - 1]);
        } else {
            L[i] = max(L[i - 1], lst[i] + 1);
        }
        ans += i - L[i] + 1;
    }
    cout << ans << '\n';

    return 0;
}
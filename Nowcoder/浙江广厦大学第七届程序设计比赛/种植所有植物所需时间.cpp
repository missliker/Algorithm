#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += x;
    }
    ans = (ans + 49) / 50;
    ans *= 5;
    cout << ans << '\n';

    return 0;
}
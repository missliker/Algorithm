#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n;
    cin >> n;

    auto check = [&](i64 x) {
        i64 q = sqrtl(x);
        return q * q == x;
    };

    i64 x = n, ans = 0, ans2 = 0;
    while (!check(x)) {
        x += 2;
        ans++;
    }
    x = n;
    while (x >= 1 and !check(x)) {
        x -= 2;
        ans2++;
    }
    if (check(x)) ans = min(ans, ans2);
    cout << ans << '\n';

    return 0;
}
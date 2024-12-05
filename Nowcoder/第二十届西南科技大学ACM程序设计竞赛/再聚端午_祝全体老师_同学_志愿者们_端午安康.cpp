#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using ld = long double;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    auto dis = [&](ld xa, ld ya, ld xb, ld yb) -> ld {
        return sqrtl((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    };

    ld xa, ya, xb, yb, xc, yc, xd, yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    ld ans = dis(xd, yd, xa, ya);
    ans += dis(xa, ya, xb, yb);
    ans += dis(xb, yb, xc, yc);
    ans += dis(xc, yc, xd, yd);
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    i64 l, r;
    cin >> l >> r;

    auto f = [&](i64 r) -> i64 {
        if (r % 4 == 0) return r;
        if (r % 4 == 1) return 1;
        if (r % 4 == 2) return r + 1;
        return 0;
    };

    i64 ans = f(r) ^ f(l - 1);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
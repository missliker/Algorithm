#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;

void Solution(int T) {
    i64 n, k, d;
    cin >> n >> k >> d;
    ld a = 4.0 - 8.0 * (k - 1) * (k - 1), b = -4.0 * n, c = 1.0 * n * n;
    ld r = (-b - sqrtl(b * b - 4.0 * a * c)) / (a * 2.0);
    ld ans = ld(1.0) * d / (r * r);
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
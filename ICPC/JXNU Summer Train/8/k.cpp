#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    double c, ans = 0;
    cin >> n >> c;
    if (n >= 10000000) {
        ans = 2.0;
    } else if (n <= 9800000) {
        ans = (1.0 * n - 9500000) / 300000;
    } else {
        ans = 1.0 + (1.0 * n - 9800000) / 200000;
    }
    ans += c;
    if (ans < 0) ans = 0;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(7);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    i64 xg, yg, xt, yt;
    cin >> xg >> yg >> xt >> yt;
    yg *= -1;
    double ans = sqrt(1.0 * (xg - xt) * (xg - xt) + (yg - yt) * (yg - yt));
    yg *= -1, xg *= -1;
    ans = min(ans, sqrt(1.0 * (xg - xt) * (xg - xt) + (yg - yt) * (yg - yt)));
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
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    i64 x, y, z;
    cin >> x >> y >> z;
    i64 ans = x + y - z;
    if (ans < 0) {
        ans = -1;
    } else if (ans == 0) {
        ans = z + 1;
    }
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
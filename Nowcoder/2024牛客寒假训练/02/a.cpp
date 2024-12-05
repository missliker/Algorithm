#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int a, b, c;
    cin >> a >> b >> c;
    int x = 0, y = 0, z = 0;
    if (a == 100) x = 0;
    else if (a == 150) x = 1;
    else if (a == 200) x = 2;
    if (b == 29 or b == 30 or b == 31 or b == 32) y = 0;
    else if (b == 34 or b == 36 or b == 40 or b == 38) y = 1;
    else y = 2;
    if (c == 29 or c == 30 or c == 31 or c == 32) z = 0;
    else if (c == 34 or c == 36 or c == 40 or c == 38) z = 1;
    else z = 2;
    int ans = x + y + z;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}

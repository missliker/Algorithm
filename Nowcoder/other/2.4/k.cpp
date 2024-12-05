#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    i64 a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    i64 f = min({a, b, c, d});
    cout << (f + e) / 2 << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}

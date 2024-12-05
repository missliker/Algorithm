#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int h;
    cin >> h;
    i64 cnt = __lg(h) + 1;
    i64 ans = (1LL << cnt) - 1;
    cout << ans << '\n';

    return 0;
}
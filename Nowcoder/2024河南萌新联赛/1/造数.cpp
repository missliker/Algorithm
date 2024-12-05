#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, ans = 0;
    cin >> n;
    if (n == 1 or n == 2) {
        cout << 1 << '\n';
        return 0;
    }
    while (n > 2) {
        // cerr << n << endl;
        if (n & 1) {
            ans++;
            n--;
        }
        if (n <= 2) break;
        n /= 2;
        ans++;
    }
    if (n) ans++;
    cout << ans << '\n';

    return 0;
}
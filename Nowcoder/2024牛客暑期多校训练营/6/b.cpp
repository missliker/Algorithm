#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, k;
    cin >> n >> k;
    k = min(k, n - k);
    if (n % 2 == 0 and k == n / 2) {
        cout << n << '\n';
        return 0;
    }
    cout << n * k + 1 << '\n';

    return 0;
}
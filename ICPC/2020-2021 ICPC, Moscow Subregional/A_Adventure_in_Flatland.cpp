#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int xa, xb, ya, yb;
    cin >> xa >> ya >> xb >> yb;
    if (xa * xb > 0 and ya * yb > 0) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }

    return 0;
}
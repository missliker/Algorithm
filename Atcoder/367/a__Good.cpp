#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010, mod = 998244853;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (c >= b) {
        if (a >= b && a < c) cout << "No" << endl;
        else cout << "Yes" << endl;
    } else {
        if (a >= b && a <= 23 || a >= 0 && a < c) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
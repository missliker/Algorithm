#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        odd += (x & 1);
    }
    if (abs(odd - (n - odd)) <= 1) {
        cout << "Good\n";
    } else {
        cout << "Not Good\n";
    }

    return 0;
}
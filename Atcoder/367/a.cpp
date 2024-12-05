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

    int A, B, C;
    cin >> A >> B >> C;

    if (B < C) {
        if (A > B and A < C) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    } else {
        if (A > B or A < C) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
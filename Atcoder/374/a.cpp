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

    string s;
    cin >> s;
    if (s.size() >= 3 and s.substr(s.size() - 3) == "san") {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
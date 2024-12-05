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
    auto a = s.substr(0, s.find('.')), b = s.substr(s.find('.') + 1);
    debug(a);
    debug(b);
    while (b.size() > 3) {
        b.pop_back();
    }
    while (b.back() == '0') {
        b.pop_back();
    }
    cout << a;
    if (not b.empty()) {
    	cout << '.' << b;
    }

    return 0;
}
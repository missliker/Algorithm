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
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto c : s) {
        c = tolower(c);
        mp[c]++;
    }
    int ans = 1E9 + 10;
    for (char c : {'s', 'h', 'a', 'n', 'g', 'i'}) {
        debug(c);
        ans = min(ans, (c == 'h' or c == 'a') ? mp[c] / 2 : mp[c]);
    }
    cout << ans << '\n';

    return 0;
}
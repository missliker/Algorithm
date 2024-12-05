#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    string s;
    cin >> s;
    if (s == string(s.size(), s.front())) {
        cout << s.size() - 1 << '\n';
        return;
    }

    int ans = 0;
    while (ans < s.size() and s[ans] == s.front()) {
        ans++;
    }
    ans = s.size() * 2 - ans;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
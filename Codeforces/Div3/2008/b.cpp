#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int n;
    string s;
    cin >> n >> s;

    int a = sqrt(n);
    if (a * a != n) {
        cout << "NO\n";
        return;
    }

    int zer = 0;
    for (auto& c : s) {
        zer += (c == '0');
    }
    debug(zer);

    int cnt = max(a - 2, 0) * max(a - 2, 0);
    debug(a, cnt);
    if (cnt == zer) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
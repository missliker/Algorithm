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
    bool ok = false;
    for (int i = 1; i < s.size(); i++) {
    	if (s[i] > s[i - 1]) {
    		ok = true;
    		break;
    	}
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
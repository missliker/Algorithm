#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int curCase) {
    string s, t = "xwr";
    cin >> s;
    for (auto& c : s) {
        int x = c - '0';
        for (int k = 2; k >= 0; k--) {
            if (x >> k & 1) {
                cout << t[k];
            } else {
            	cout << '-';
            }
        }
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int maxCase = 1;
    cin >> maxCase;
    for (int curCase = 1; curCase <= maxCase; curCase++) {
        Solution(curCase);
    }

    return 0;
}
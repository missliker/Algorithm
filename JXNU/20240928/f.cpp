#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int curCase) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int ans = ranges::max(a);
    cout << ans << '\n';
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
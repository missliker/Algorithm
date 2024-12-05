#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

i64 dp[20][10];

void Solution(int curCase) {
    i64 n, x;
    cin >> n >> x;
    memset(dp, 0, sizeof dp);
    int m = 0, nn = n;
    while (nn) {
    	m++;
    	nn /= 10;
    }
    debug(m);

    for (int i = m; i > 0; i--) {
    	for (int j = 0; j <= 9; j++) {
    		if (j == x) {
    			dp[i][j] = 0;
    			continue;
    		}
    		dp[i][j] = 1;
    		for (int k = 0; k <= 9; k++) {
    			if (k == x) {
    				continue;
    			}
    			dp[i][j] += dp[i - 1][k];
    		}
    	}
    }

    i64 ans = 0;
    for (int i = m; i >= 1; i--) {
    	for (int j = 0; j <= 9; j++) {
    		if (j == x) {
    			continue;
    		}
    		ans += dp[i][j];
    	}
    }
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
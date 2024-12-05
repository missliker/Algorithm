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
    int ans = 0, lst = 0;
    for (int i = 0; i < s.size(); i++) {
    	if (s[i] == 'A') {
    		lst = i;
    		break;
    	}
    }

    for (int i = 0; i < 26; i++) {
    	char c = 'A' + i;
    	for (int j = 0; j < s.size(); j++) {
    		if (s[j] == c) {
    			ans += abs(j - lst);
    			lst = j;
    			break;
    		}
    	}
    }
    cout << ans << '\n';

    return 0;
}
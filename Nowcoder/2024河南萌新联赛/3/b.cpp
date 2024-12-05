#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string s;
        cin >> s;
        s += '.';
        int i = 0, now = 0, ok = 1;
        while (i < s.size()) {
            if (s[i] == '.') {
                if (now >= 0 and now <= 255) {
                    now = 0;
                } else {
                    ok = false;
                    break;
                }
            } else {
                now = now * 10 + (s[i] - '0');
            }
            i++;
        }
    	if (ok) ans++;
    }
    cout << ans << '\n';

    return 0;
}
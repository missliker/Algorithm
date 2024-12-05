#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int n = 10;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m += a[i];
    }

    string ans;
    int ban = 0, ned = 0;
    while (m--) {
        bool can = false;
        for (int i = 0; i < n; i++) {
            if (a[i] and i != ban) {
                ans += ('0' + i);
                a[i]--;
                ban = i;
                can = true;
                break;
            }
        }
        if (not can) {
            ans += ('0' + ban);
            a[ban]--;
            ned++;
        }
    }
    debug(ans);
    debug(ned);
    if (ned == 0) {
        cout << ans << '\n';
        return;
    }
    string pre;
    for (int i = int(ans.size()) - 1; i >= 0; i--) {
        if (ans[i] != ('0' + ban)) {
            pre = ans.substr(0, i + 1);
            break;
        }
    }
    if (pre.size() < ned) {
        cout << "-1\n";
        return;
    }

    debug(pre);
    for (int i = 0; i < pre.size() - ned; i++) {
        cout << pre[i];
    }

    cout << ban;
    string suf;
    for (int i = int(pre.size()) - 1; i >= int(pre.size()) - ned; i--) {
        suf += pre[i];
        suf += char('0' + ban);
    }
    debug(suf);
    cout << suf << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
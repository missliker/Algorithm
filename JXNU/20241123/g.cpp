#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int curCase) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector id(n + 1, vector<int>(1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[a[i]].emplace_back(i);
    }

    vector<int> lst(n + 1), nxt(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (id[i].size() < k + 1) {
            continue;
        }
        for (int l = 1, r = k; r < id[i].size(); l++, r++) {
            lst[id[i][l]] = id[i][l - 1];
            nxt[id[i][l]] = id[i][r];
        }
    }
    debug(lst);
    debug(nxt);

    vector<int> L(n + 1), R(n + 1);
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        while (not stk.empty() and a[stk.top()] <= a[i]) {
            stk.pop();
        }
        if (stk.empty()) {
            L[i] = 0;
        } else {
            L[i] = stk.top();
        }
        stk.emplace(i);
    }
    debug(L);
    stk = stack<int>();
    for (int i = n; i >= 1; i--) {
        while (not stk.empty() and a[stk.top()] <= a[i]) {
            stk.pop();
        }
        if (stk.empty()) {
            R[i] = n + 1;
        } else {
            R[i] = stk.top();
        }
        stk.emplace(i);
    }
    debug(R);

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (nxt[i] == -1) {
            continue;
        }
        int ansl = i - max(lst[i], L[i]), ansr = R[i] - nxt[i];
        if (ansl <= 0 or ansr <= 0 or ansl > n or ansr > n) {
            continue;
        }
        int ask1l = max(lst[i], L[i]), ask1r = i - 1, ask2l = nxt[i], ask2r = R[i] - 1;
        debug(ask1l, ask1r);
        debug(ask2l, ask2r);
        debug(ansl, ansr);
        ans += 1LL * ansl * ansr;
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
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    map<int, i64> cnt;
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    priority_queue<i64> h;
    set<int> st(a.begin(), a.end());
    for (auto& x : st) h.push(x);
    for (int i = 0; i < n; i++) cnt[a[i]] = b[i];
    constexpr int K = 2E7 + 10;
    vector<i64> dp(K + 1);
    int lst = 0;
    for (int i = 1; i <= K; i++) {
        dp[i] = dp[i - 1];
        if (h.empty()) 
        auto t = h.top();
        h.pop();
        if (t == lst) {
            auto t2 = h.top();
            h.pop();
            while (cnt[t2] == 0) {
                t2 = h.top();
                h.pop();
            }
            cnt[t2]--;
            dp[i] += t2;
            lst = t2;
            if (cnt[t] != 0) h.push(t);
            if (cnt[t2] != 0) h.push(t2);
        } else {
            while (cnt[t] == 0) {
                auto t = h.top();
                h.pop();
            }
            cnt[t]--;
            dp[i] += t;
            lst = t;
            if (cnt[t] != 0) h.push(t);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << dp[k] << '\n';
    }

    return 0;
}
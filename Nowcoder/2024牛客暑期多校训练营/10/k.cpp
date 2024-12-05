#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
// #define ull unsigned long long
#define int long long
const int N = 1e6 + 10, mod = 998244353, P = 131, inf = 1e18;
int n, m;
// int a[N];
void solve() {
    cin >> n;
    vector<int> a, b;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 0) ans++;
        else if (x < 0) a.push_back(x);
        else b.push_back(x);
    }
    int res = 0;
    for (int i = 0; i < b.size(); i++) {
        int x = b[i];
        // cout << x << " " ;
        if (b.size() - i - 1 < x) break;
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            int tx = x - a[mid];
            if (mid >= tx) r = mid;
            else l = mid + 1;
        }
        if (l < a.size()) {
            int tx = x - a[l];
            if (l < tx) l++;
        }
        int cnt1 = i + 1, cnt2 = a.size() - l;
        res = max(res, cnt1 + cnt2);
        // cout << i << " " << l << '\n';
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        int x = a[i];
        if (i < -x) break;
        int l = 0, r = b.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            int tx = b[mid] - x;
            if (b.size() - mid - 1 >= tx) l = mid;
            else r = mid - 1;
        }
        if (l < b.size()) {
            int tx = b[l] - x;
            if (b.size() - l - 1 < tx) l--;
        }
        if (b.size() == 0) l = -1;
        int cnt1 = a.size() - i, cnt2 = l + 1;
        res = max(res, cnt1 + cnt2);
        // cout << i << " " << l << '\n';
    }
    cout << ans + res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
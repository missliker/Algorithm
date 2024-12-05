#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (k >= n) {
        cout << n << '\n';
        return 0;
    }
    priority_queue<i64, vector<i64>, greater<i64>> q;
    for (int i = 1; i <= min(k, n); i++) q.push(a[i]);

    if (q.empty()) {
        for (int i = 1; i <= n; i++) {
            if (m > a[i]) {
                m -= a[i];
            } else {
                cout << i - 1 << '\n';
                return 0;
            }
        }
        cout << n << '\n';
    } else {
        for (int i = k + 1; i <= n; i++) {
            if (a[i] > q.top()) {
                if (m > q.top()) {
                    m -= q.top();
                    q.pop();
                    q.push(a[i]);
                } else {
                    cout << i - 1 << '\n';
                    return 0;
                }
            } else {
                if (m > a[i]) {
                    m -= a[i];
                } else {
                    cout << i - 1 << '\n';
                    return 0;
                }
            }
        }
        cout << n << '\n';
    }

    return 0;
}
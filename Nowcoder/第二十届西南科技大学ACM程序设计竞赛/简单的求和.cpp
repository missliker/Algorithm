#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    priority_queue<i64> q;
    for (int l = 1; l <= n; l++) {
        for (int len = 1; l + len - 1 <= n; len++) {
            int r = l + len - 1;
            i64 now = s[r] - s[l - 1] + k * k + (r * r - l * l + r + l) / 2;
            q.push(now);
            if (q.size() >)
        }
    }

    return 0;
}
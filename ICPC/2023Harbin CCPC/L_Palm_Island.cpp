#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve(int Case) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), v(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] -= 1;
        pos[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        v[i] = pos[a[i]];
        // cout << v[i] << " \n"[i == n - 1];
    }
    string ans;
    int curr = 0;
    while (true) {
        if (!curr and is_sorted(v.begin(), v.end()))
            break;
        if (curr < n - 1 and v[curr] > v[curr + 1]) {
            swap(v[curr], v[curr + 1]);
            curr++;
            ans += "2";
        } else {
            ans += "1";
            curr++;
        }
        curr %= n;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int Cases, Case = 1;
    cin >> Cases;
    while (Case <= Cases)
        solve(Case++);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<i64> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    i64 sum = v[1], ans = sum;
    for (int i = 2; i <= n; i++) {
        sum = max(sum + v[i], v[i]);
        ans = max(ans, sum);
    }
    if (k == 0) {
        cout << ans << '\n';
    } else {
        for (int j = 1; j < n; j++) {
            swap(v[j], v[j + 1]);
            i64 sonsum = v[1], sonans = sonsum;
            for (int i = 2; i <= n; i++) {
                sonsum = max(sonsum + v[i], v[i]);
                sonans = max(sonans, sonsum);
            }
            swap(v[j], v[j + 1]);
            ans = max(ans, sonans);
        }
        cout << ans << '\n';
    }
    return 0;
}

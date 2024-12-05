#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i <= k) cnt[a[i]]++;
    }

    auto check = [&]() -> bool {
        return cnt.size() == k and cnt.begin()->first == 1 and cnt.rbegin()->first == k;
    };

    int ans = check();
    for (int i = 2; i + k - 1 <= n; i++) {
        cnt[a[i + k - 1]]++;
        cnt[a[i - 1]]--;
        if (cnt[a[i - 1]] == 0) cnt.erase(a[i - 1]);
        ans += check();
    }
    cout << ans << '\n';

    return 0;
}
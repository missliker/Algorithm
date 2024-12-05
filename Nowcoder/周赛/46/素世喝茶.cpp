#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, x;
    cin >> n >> x;
    x--;
    vector<int> a(n);
    map<int, int> mp;
    for (auto& x : a) {
        cin >> x;
        mp[x]++;
    }
    auto it = mp.rbegin();
    int ans = 0;
    if (it->first == a[x]) {
        ans = it->second - 1;
        if (ans == 0) {
            it++;
            ans = it->second;
        }
    } else {
        ans = it->second;
    }
    cout << ans << '\n';

    return 0;
}
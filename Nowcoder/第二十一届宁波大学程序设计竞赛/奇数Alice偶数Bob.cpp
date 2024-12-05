#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (n & 1) {
        cout << "Yukimi\n";
        return 0;
    }
    int mn = *min_element(a.begin(), a.end());
    int ans = 0;
    for (auto& x : a) {
        if (x != mn) ans++;
    }
    cout << (ans % 2 == 0 ? "LCF" : "Yukimi") << '\n';

    return 0;
}
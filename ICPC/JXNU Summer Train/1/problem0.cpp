#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& i : a) cin >> i;
    if (n == 1) {
        cout << a.front() << '\n';
        return 0;
    }
    ranges::sort(a.begin(), a.end());
    cout << fixed << setprecision(1) << min(1.0 * a[1], (a.front() + a.back()) / 2.0) << '\n';

    return 0;
}
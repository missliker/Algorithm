#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    auto xnor = [&](int x, int y) -> int {
    	int res = (x ^ y);
    	res ^= (1LL << m) - 1;
    	return res;
    };

    int ans = 0;
    for (int i = 1; i < n; i++) {
    	ans = max(ans, xnor(a[i], a[i - 1]));
    }
    cout << ans << '\n';

    return 0;
}
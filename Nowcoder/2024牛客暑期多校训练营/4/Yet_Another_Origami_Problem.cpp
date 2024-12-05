#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    int ans = a[1] - a[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, a[i] - a[i - 1]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
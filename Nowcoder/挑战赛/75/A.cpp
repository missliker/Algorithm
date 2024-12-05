#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    i64 ans = 0;
    if (n & 1) {
    	i64 cnt = n / 2;
    	ans = cnt + 1 + (2 + cnt + 1) * cnt / 2;
    } else {
    	n--;
    	i64 cnt = n / 2;
    	ans = cnt + 1 + (2 + cnt + 1) * cnt / 2;
    	ans++;
    }
    cout << ans << '\n';

    return 0;
}
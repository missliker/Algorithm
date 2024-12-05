#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using d64 = long double;
const d64 Pi = acos(-1);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    }

    d64 eps = 1000000000;
    int ans = -1;
    for (int i = 0; i < n; i++) {
    	if (fabs(Pi * b[i] - a[i]) < eps) {
    		eps = fabs(Pi * b[i] - a[i]);
    		ans = i;
    	}
    }
    cout << a[ans] << ' ' << b[ans] << '\n';

    return 0;
}
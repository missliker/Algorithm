#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    i64 x, y, a, b;
    cin >> x >> y >> a >> b;
    i64 g = gcd(x, y);
    x /= g, y /= g;
    i64 z = x + y;
    if ((z & (z - 1)) != 0) {
    	cout << "-1\n";
    	return;
    }
    cout << int(log2(z) + 1) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
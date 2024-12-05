#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int A, B, C, n, W;
    cin >> A >> B >> C >> n >> W;
    vector<int> t{A, B, C};
    sort(t.begin(), t.end(), greater<int>());
    A = t[0], B = t[1], C = t[2];

    auto calc = [&](int x, int y, int z) -> i64 {
    	i64 res = 1LL * x * A + 1LL * y * B + 1LL * z * C;
    	return res;
    };

    i64 ans = 1E18 + 10;
    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j <= n - i; j++) {
    		int k = n - i - j;
    		if (abs(W - calc(i, j, k)) < ans) {
    			ans = abs(W - calc(i, j, k));
    		}
    	}
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
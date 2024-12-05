#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, k;
    cin >> n >> k;

    int now = 1;
    vector<int> st(n + 1);
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j * i <= n; j += 2) {
    		if (st[i * j]) continue;
    		st[i * j] = now;
    		if (now == k) {
    			cout << i * j << '\n';
    			return;
    		}
    		now++;
    	}
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
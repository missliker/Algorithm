#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    auto check = [&](int x) {
    	string t = s;
    	int cnt = 0;
    	for (int i = 0; i < n;) {
    		if (t[i] == '1') {
    			int j = i;
    			while (j < min(n, i + x)) t[j++] = '0';
    			i = j + 1;
    			cnt++;
    		} else {
    			i++;
    		}
    	}
    	return cnt <= k;
    };

    int lo = 0, hi = n;
    while (lo < hi) {
    	int mi = (lo + hi) >> 1;
    	if (check(mi)) hi = mi;
    	else lo = mi + 1;
    }
    cout << lo + 1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
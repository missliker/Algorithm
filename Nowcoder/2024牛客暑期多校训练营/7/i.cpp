#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int m, k, h;
    cin >> m >> k >> h;
    int lo = 0, hi = h;

    auto check = [&](int x) -> bool {
    	int cnt = x, now = x;
    	while (now / m > 0) {
    		now = now / m * k + now % m;
    	}
    }

    while (lo < hi) {
    	int mi = (lo + hi) >> 1;
    	if (check(mi)) {
    		hi = mi;
    	} else {
    		lo = mi + 1;
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
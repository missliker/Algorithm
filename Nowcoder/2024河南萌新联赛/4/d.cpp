#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
	i64 x;
	cin >> x;
	for (i64 i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2E5 + 10;
int a[N];
i64 f[N];

void Solution(int T) {
	int l, r;
	cin >> l >> r;
	cout << f[r] - f[l - 1] + a[l] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    for (int i = 1; i < N; i++) {
    	a[i] = a[i / 3] + 1;
    }
    for (int i = 1; i < N; i++) {
    	f[i] = f[i - 1] + a[i];
    }

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
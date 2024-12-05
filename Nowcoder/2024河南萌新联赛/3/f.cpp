#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2E6 + 10;
i64 f[N];

void Solution(int T) {
    i64 x, y;
    cin >> x >> y;
    cout << f[x + y] - f[x] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    for (int i = 1; i < N; i++) {
        i64 x = i - 1, y = i, cnt = 0;
        for (int j = 0; j < 63; j++) {
            if ((x >> j & 1) != (y >> j & 1)) cnt++;
        }
        f[i] = f[i - 1] + cnt;
    }

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
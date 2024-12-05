#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int x, y, k;
    cin >> x >> y >> k;
    if (k & 1) {
        cout << x << ' ' << y << '\n';
    }
    for (int i = 0; i < k / 2; i++) {
        int Ax = i + 1 - 10000, Ay = i + 1 - 10000;
        int Bx = x * 2 - Ax, By = y * 2 - Ay;
        cout << Ax << ' ' << Ay << '\n' << Bx << ' ' << By << '\n';
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
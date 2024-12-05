#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    double a1, b1, c1, a2, b2, c2, x1, x2, d, n, m, a, b, c;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    a = a1 * b2, b = a2 + b1 * b2, c = b2 * c1 + c2;
    d = b * b - 4 * a * c;
    if (a1 == 0 or b2 == 0) {
        cout << "1\n";
        return;
    }
    if (d >= 0) {
        cout << "2\n";
    } else {
        cout << "INF\n";
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
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    auto ask = [&](int a, int b) -> int {
        cout << "? " << a << ' ' << b << endl;
        int res;
        cin >> res;
        return res;
    };

    int lo = 0, hi = 1000;
    while (lo < hi) {
        int x = lo + (hi - lo) / 3;
        int y = lo + (hi - lo) * 2 / 3;
        int res = ask(x, y);
        if (x * y == res) {
            lo = y + 1;
        } else if (x * (y + 1) == res) {
            lo = x + 1;
            hi = y;
        } else {
            assert((x + 1) * (y + 1) == res);
            hi = x;
        }
    }

    cout << "! " << lo << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
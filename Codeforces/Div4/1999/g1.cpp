#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    auto ask = [&](char c, int a, int b) -> int {
        cout << c << ' ' << a << ' ' << b << endl;
        int res;
        cin >> res;
        return res;
    };

    auto check = [&](int x) -> bool {
        int y = 1;
        int res = ask('?', x, y);
        return x * y < res;
    };

    int lo = 0, hi = 1000;
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (check(mi)) {
            hi = mi;
        } else {
            lo = mi + 1;
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
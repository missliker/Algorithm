#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Y;
    cin >> Y;

    auto get = [&](int x) {
        if (x % 4 == 0 and x % 100 != 0 or x % 400 == 0) return 366;
        return 365;
    };

    cout << get(Y) << '\n';

    return 0;
}
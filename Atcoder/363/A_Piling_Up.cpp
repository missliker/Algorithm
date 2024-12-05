#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int R;
    cin >> R;
    cout << (R / 100 + 1) * 100 - R << '\n';

    return 0;
}
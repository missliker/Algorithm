#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 a, b;
    cin >> a >> b;
    cout << (a - b) - b * 10 << endl;

    return 0;
}
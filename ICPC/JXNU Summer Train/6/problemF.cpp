#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;

    auto ask = [&](int i, int j, int x) {
        cout << "? " << i << ' ' << j << ' ' << x << endl;
        int res;
        cin >> res;
        return res;
    };

    return 0;
}
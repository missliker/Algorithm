#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    if (n > 10) {
        cout << -1 << '\n';
    } else {
        vector<int> t{1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < n; i++) {
            cout << t[i];
        }
    }

    return 0;
}
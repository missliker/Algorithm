#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double ans = a[1], div = 0, lst = 0;
    if (ans > 0) {
        cout << "+";
    } else if (ans < 0) {
        cout << "-";
    } else {
        cout << "0";
    }
    for (int i = 2; i <= n; i++) {
        lst = ans;
        ans = ans / 2 + a[i];
        if (ans > 0) {
            cout << "+";
        } else if (ans < 0) {
            cout << "-";
        } else {
            if (div == 0) {
                cout << "0";
            } else {
                if (div > 0) {
                    cout << "+";
                } else {
                    cout << "-";
                }
            }
        }
        div += (lst - (ans - a[i]) * 2);
    }

    return 0;
}
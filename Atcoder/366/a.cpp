#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, T, A;
    cin >> N >> T >> A;
    if (N - T - A < abs(T - A)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
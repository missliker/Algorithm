#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    i64 s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    cout << (s % 2 == 0 ? "Bob" : "Alice") << '\n';

    return 0;
}
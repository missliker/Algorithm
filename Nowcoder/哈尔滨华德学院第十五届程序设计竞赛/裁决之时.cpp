#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    while (N--) {
        int A;
        cin >> A;
        cout << (A >= 60 ? "AC" : "WA") << '\n';
    }

    return 0;
}
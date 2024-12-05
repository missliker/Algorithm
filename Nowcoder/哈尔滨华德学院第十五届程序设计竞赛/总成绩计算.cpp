#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    while (N--) {
        int A, B;
        cin >> A >> B;
        cout << int(ceil((4 * A + 6 * B) / 10.0)) << '\n';
    }

    return 0;
}
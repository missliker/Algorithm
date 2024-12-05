#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int T, O;
    cin >> T >> O;
    if (T == O) {
        cout << "even even seven EIeven.\n";
    } else if (T > O) {
        cout << "orz teralem is the king!\n";
    } else {
        cout << "orz overflowker is the king!\n";
    }

    return 0;
}
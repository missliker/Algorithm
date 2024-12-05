#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int R, G, B;
    cin >> R >> G >> B;
    string C;
    cin >> C;
    if (C == "Red") {
        cout << min(G, B) << '\n';
    } else if (C == "Green") {
        cout << min(R, B) << '\n';
    } else {
        cout << min(R, G) << '\n';
    }

    return 0;
}
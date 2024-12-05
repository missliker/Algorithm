#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int B, R, D, S;
    cin >> B >> R >> D >> S;
    if (R == 0 and D != 0) {
        cout << "gua!\n";
        return;
    }
    if ((R * S + 59) / 60 + 1 < (D + B - 1) / B) {
        cout << "gua!\n";
    } else {
        cout << "ok\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
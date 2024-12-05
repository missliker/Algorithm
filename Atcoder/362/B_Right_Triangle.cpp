#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Xa, Ya, Xb, Yb, Xc, Yc;
    cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc;

    auto dis = [&](int Xa, int Ya, int Xb, int Yb) -> ld {
        ld res = ld(1.0) * (Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb);
        return res;
    };

    ld A = dis(Xb, Yb, Xc, Yc), B = dis(Xa, Ya, Xc, Yc), C = dis(Xa, Ya, Xb, Yb);
    if (A == B + C or B == A + C or C == A + B) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
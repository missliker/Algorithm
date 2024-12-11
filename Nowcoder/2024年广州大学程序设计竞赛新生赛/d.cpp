#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Ax, Ay, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Cx >> Cy >> Dx >> Dy;
    int Bx = Ax + (Cx - Ax) / 3, By = Ay + (Cy - Ay) / 3;
    i64 ans = 1LL * (Dx - Bx) * (Dx - Bx) + (Dy - By) * (Dy - By);
    cout << ans << '\n';

    return 0;
}
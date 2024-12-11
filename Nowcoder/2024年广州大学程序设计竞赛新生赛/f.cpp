#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void f(int& xA, int& tA, int& xB, int& tB, int L, int v, int k) {
    while (k > 0) {
        int collide_time = abs(xA - xB) / (2 * v);
        int wall_time_A = tA > 0 ? (L - xA) / v : xA / v;
        int wall_time_B = tB > 0 ? (L - xB) / v : xB / v;
        int next_event_time = min({collide_time, wall_time_A, wall_time_B, k});

        xA += tA * v * next_event_time;
        xB += tB * v * next_event_time;
        k -= next_event_time;

        if (next_event_time == collide_time and xA == xB) {
            tA = -tA;
            tB = -tB;
        }
        if (next_event_time == wall_time_A) tA = -tA;
        if (next_event_time == wall_time_B) tB = -tB;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int L, v, k, xA, tA, xB, tB;
    cin >> L >> v >> k >> xA >> tA >> xB >> tB;

    f(xA, tA, xB, tB, L, v, k);
    cout << xA << ' ' << xB << '\n';

    return 0;
}
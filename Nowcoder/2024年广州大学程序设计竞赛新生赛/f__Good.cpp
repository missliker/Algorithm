#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void redir(int& pos, int& dir, int boundary) {
    if (pos == 0 or pos == boundary) {
        dir = -dir;
    }
}

void run(int& posA, int& dirA, int& posB, int& dirB, int speed, int boundary) {
    posA += dirA * speed;
    posB += dirB * speed;

    redir(posA, dirA, boundary);
    redir(posB, dirB, boundary);

    if (posA == posB) {
        dirA = -dirA;
        dirB = -dirB;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int L, v, xa, ta, xb, tb, k;
    cin >> L >> v >> k >> xa >> ta >> xb >> tb;

    while (k > 0) {
        int time_step = 1;
        if (ta > 0) time_step = min(time_step, (L - xa) / v);
        if (ta < 0) time_step = min(time_step, xa / v);
        if (tb > 0) time_step = min(time_step, (L - xb) / v);
        if (tb < 0) time_step = min(time_step, xb / v);

        time_step = min(time_step, k);
        run(xa, ta, xb, tb, time_step * v, L);
        k -= time_step;
    }
    cout << xa << ' ' << xb << '\n';

    return 0;
}
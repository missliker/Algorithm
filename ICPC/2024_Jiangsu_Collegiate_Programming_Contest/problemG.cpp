#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int B, t1, a1, t2, a2;
    cin >> B >> t1 >> a1 >> t2 >> a2;
    bool re = false;
    if (t1 == t2 and a1 > a2) {
        re = true;
        swap(a1, a2);
    }
    int time1 = t2 - t1;
    double have1 = 1.0 * time1 * B;
    double ans1, ans2;
    if (have1 >= a1) {
        ans1 = 1.0 * a1 / B;
        ans2 = 1.0 * a2 / B;
    } else {
        ans1 = time1;
        double time2 = (a1 - have1) * 2.0 / B;
        double have2 = 1.0 * time2 * B / 2;
        ans2 = 0;
        if (have2 >= a2) {
            ans2 = a2 * 2.0 / B;
            ans1 += ans2;
            ans1 += 1.0 * (a1 - have1 - 1.0 * ans2 * B / 2) / B;
        } else {
            ans1 += time2;
            ans2 = time2;
            ans2 += 1.0 * (a2 - have2) / B;
        }
    }
    if (re) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
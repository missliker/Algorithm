#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    i64 ans = 0;
    do {
        i64 res = 0, now = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > now) {
                now++;
            } else if (a[i] < now) {
                now--;
            } else {
                res++;
            }
        }
        ans = max(ans, res);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
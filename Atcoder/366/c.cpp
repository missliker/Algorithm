#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Q;
    cin >> Q;
    map<int, int> cnt;

    while (Q--) {
        int o, x;
        cin >> o;
        if (o == 1) {
            cin >> x;
            cnt[x]++;
        } else if (o == 2) {
            cin >> x;
            cnt[x]--;
            if (cnt[x] == 0) cnt.erase(x);
        } else {
            cout << cnt.size() << '\n';
        }
    }

    return 0;
}
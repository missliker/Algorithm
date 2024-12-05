#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> st(n);
    st[a.front()] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - 1 >= 0) {
            if (st[a[i] - 1]) {
                st[a[i]] = 1;
                continue;
            }
        }
        if (a[i] + 1 < n) {
            if (st[a[i] + 1]) {
                st[a[i]] = 1;
                continue;
            }
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
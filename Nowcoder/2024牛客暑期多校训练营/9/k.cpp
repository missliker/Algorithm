#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1E7 + 10;
int f[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < N; i++) {
        f[i] = min(f[i - 1] + 1, f[i / k] + 1);
    }

    ranges::sort(a);
    for (int i = 0; i < n; i++) {
        cout << f[a[i]] << " \n"[i == n - 1];
    }
    for (int i = 0; i <= a.back(); i++) {
        cout << "-1: " << i << ' ';
        for (int j = 0; j < n; j++) {
            cout << (a[j] - i >= 0 ? f[a[j] - i] : 0) << " \n"[j == n - 1];
        }
    }

    return 0;
}
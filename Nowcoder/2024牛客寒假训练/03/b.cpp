#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++)  cin >> x;
    cout << ((n & 1) ? "qcjj\n" : "zn\n");
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}


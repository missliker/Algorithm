#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    string a, b;
    cin >> a >> b;
    a[0] = toupper(a[0]);
    b[0] = toupper(b[0]);
    cout << (a[0] == b[0] ? "Yes\n" : "No\n");
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}

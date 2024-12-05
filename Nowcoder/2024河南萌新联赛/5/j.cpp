#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    i64 n;
    cin >> n;
    i64 m = sqrtl(n);
    cout << m << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
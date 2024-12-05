#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, s;
    cin >> n >> s;
    int cnt = (n + 1) / 2 - 1;
    cout << s / (n - cnt) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
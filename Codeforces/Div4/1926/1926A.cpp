#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    string s;
    cin >> s;
    int a = ranges::count(s, 'A'), b = ranges::count(s, 'B');
    cout << (a > b ? "A" : "B") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
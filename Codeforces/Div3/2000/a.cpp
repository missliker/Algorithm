#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    string s;
    cin >> s;
    if (s.size() <= 2 or s.substr(0, 2) != "10") {
        cout << "NO\n";
        return;
    }
    string x = s.substr(2);
    if (stoi(x, 0, 10) >= 2 and x.front() != '0') {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    string s;
    cin >> s;

    sort(s.begin(), s.end(), [&](char lth, char rth) { return lth > rth; });

    int eve = -1;
    for (int i = 0; i < s.size(); i++) {
        if (int(s[i] - '0') % 2 == 0) {
            eve = i;
            break;
        }
    }
    if (eve == -1) {
        cout << "97531\n";
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (i == eve) continue;
        cout << s[i];
    }
    cout << s[eve] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
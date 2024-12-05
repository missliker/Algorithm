#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n;
    string str;
    cin >> n >> str;
    bool d, f, s, D, F, S;
    d = f = s = D = F = S = false;
    for (auto c : str) {
        if (c == 'd') d = true;
        else if (c =='D') D = true;
        else if (c == 'f' and d) f = true;
        else if (c == 'F' and D) F = true;
        else if (c == 's' and f) s = true;
        else if (c == 'S' and F) S = true;
   }
    cout << int(S) << ' ' << int(s) << '\n';
}
int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}

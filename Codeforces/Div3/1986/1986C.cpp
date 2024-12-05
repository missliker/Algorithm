#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, m;
    cin >> n >> m;
    string s, c;
    cin >> s;
    vector<int> ind(m);
    for (auto& i : ind) cin >> i;
    cin >> c;
    sort(ind.begin(), ind.end());
    ind.erase(unique(ind.begin(), ind.end()), ind.end());
    sort(c.begin(), c.end());
    m = ind.size();
    for (int i = 0; i < m; i++) s[ind[i] - 1] = c[i];
    cout << s << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
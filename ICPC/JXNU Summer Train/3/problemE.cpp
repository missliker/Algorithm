#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        a[i] -= i;
        b[i] = i - b[i];
    }

    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), [&](int i, int j) {
        if (a[i] == a[j]) return b[i] < b[j];
        return a[i] < a[j];
    });

    vector<int> tp;
    for (int i = 1; i <= n; i++) {
        int j = p[i];
        if (tp.empty() or b[j] < tp.back()) {
            tp.emplace_back(b[j]);
        } else if (b[j] >= tp.back()) {
            auto tmp = tp.back();
            while (not tp.empty() and b[j] >= tp.back()) tp.pop_back();
            tp.emplace_back(tmp);
        }
    }
    cout << tp.size() << '\n';

    return 0;
}
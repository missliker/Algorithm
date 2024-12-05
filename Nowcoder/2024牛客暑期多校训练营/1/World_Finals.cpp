#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
    string name;
    int p, t;
};

bool operator<(const Info& l, const Info& r) {
    if (l.p == r.p) return l.t < r.t;
    return l.p > r.p;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    set<Info> A, B, ALL;
    vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].p >> a[i].t;
        A.insert(a[i]);
    }
    int m;
    cin >> m;
    vector<Info> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].name >> b[i].p >> b[i].t;
        if (A.find(b[i]) != A.end()) {
            A.erase(b[i]);
            ALL.insert(b[i]);
        } else {
            B.insert(b[i]);
        }
    }

    return 0;
}
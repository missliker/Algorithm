#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using Pair = pair<i64, i64>;
ostream& operator<<(ostream& os, Pair n) {
    string a, b, s, flag;
    if (n.first < 0) flag = "-", n.first *= -1;
    while (n.first) {
        a += '0' + n.first % 10;
        n.first /= 10;
    }
    a += flag;
    reverse(a.begin(), a.end());
    flag = string("");
    if (n.second < 0) flag = "-", n.second *= -1;
    while (n.second) {
        b += '0' + n.second % 10;
        n.second /= 10;
    }
    b += flag;
    reverse(b.begin(), b.end());
    s = "[" + a + ", " + b + "]\n";
    return os << s;
}

struct Info {
    i64 l, r;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<Info> v(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        v[i].l = a[i], v[i].r = b[i];
    }
    vector<int> p(n), pa(n), mxb(n);
    iota(pa.begin(), pa.end(), 0);
    sort(pa.begin(), pa.end(), [&](int i, int j) {
        return a[pa[i]] < a[pa[j]];
    });
    priority_queue<int> q;
    q.push(b[pa[n - 1]]);
    for (int i = n - 2; i >= 0; i--) {
        int j = pa[i];
        mxb[j] = q.top();
        q.push(b[j]);
    }
    priority_queue<Pair> sma;
    priority_queue<Pair, vector<Pair>, greater<Pair>> big;
    vector<int> mnb(n);
    big.push({b[0], 0});
    for (int i = 1; i < n; i++) {
        int j = pa[i];
        mnb[j] = 
    }
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        if (v[i].l == v[j].l) return v[i].r < v[j].r;
        return v[i].l < v[j].l;
    });
    multiset<i64> R;
    for (int i = 1; i < n; i++) R.insert(v[i].r);
    vector<i64> ans(n);
    for (int i = 0; i < n; i++) {
        //
        cout << v[p[i]].l << ' ' << v[p[i]].r << endl;
        if (i == n - 1) { continue; }
        i64 jr = *R.rbegin();
        if (jr >= v[p[i]].r) {
            ans[p[i]] = 0;
        } else {
            ans[p[i]] = v[p[i]].r - jr;
        }
        // auto wait = R.lower_bound(a[p[i]].r);
        // R.erase(wait);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';

    return 0;
}
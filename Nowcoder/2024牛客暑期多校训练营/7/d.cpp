#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2E5 + 10;
int a[N], pos[N];

struct Info {
    int l;
    int r;
};

void Solution(int T) {
    int n, k;
    cin >> n >> k;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[i] = i / sz;
    }

    vector<Info> query;
    int m = 0;
    for (int len = k; len <= n; len += k) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            Info t;
            t.l = l, t.r = r;
            query.emplace_back(t);
            m++;
        }
    }
    sort(query.begin(), query.end(), [&](Info x, Info y) {
        // return pos[x.l] == pos[y.l] ? x.r < y.r : pos[x.l] < pos[y.l];
        if (pos[x.l] ^ pos[y.l]) return pos[x.l] < pos[y.l];
        return ((pos[x.l] & 1) ? x.r < y.r : x.r > y.r);
    });

    map<int, int> now;
    auto add = [&](int i) {
        now[a[i]]++;
    };

    auto sub = [&](int i) {
        now[a[i]]--;
        if (now[a[i]] == 0) {
            now.erase(a[i]);
        }
    };

    int l = 1, r = 0;
    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        while (query[i].l < l) add(--l);
        while (query[i].r > r) add(++r);
        while (query[i].l > l) sub(l++);
        while (query[i].r < r) sub(r--);
        int res = 1;
        if (k * now.size() != r - l + 1) continue;
        for (auto& [x, y] : now) {
            if (y != k) {
                res = 0;
                break;
            }
        }
        ans += res;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
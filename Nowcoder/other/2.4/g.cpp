#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

inline i64 read() {
    i64 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' or ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' and ch <= '9') {
        x = ((x << 3) + (x << 1)) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

inline void print(i64 x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int n, m;
    n = read(); m = read();
    set<i64> st;
    vector<i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        st.insert(i);
    }
    while (m --) {
        int o, p, x;
        o = read();
        if (o == 1) {
            p = read(); x = read();
            if (st.find(p) != st.end()) {
                v[p] -= x;
                if (v[p] <= 0) {
                    auto it = st.lower_bound(p);
                    if (p == *it) st.erase(it);
                }
            }
        } else {
            p = read();
            auto it = st.lower_bound(p);
            i64 ans = *it;
            if (it == st.end()) ans = n;
            print(ans); puts("");
        }
    }
    return 0;
}

[题目链接](https://codeforces.com/gym/104095/problem/J)

# 题意

请你维护一个长度为 *n* 的非负整数序列 *a*，支持以下两种操作：

1.  第一种操作会将序列 a[l~r] 中的每个元素，修改为各自和 *x* 的"二进制与"（AND）的值，其中 *l*, *r*, *x* 在每次操作时会给定；
2.  第二种操作会询问序列 a[l~r] 中所有元素的平方和模 998 244 353 的值，即 ![img](D:\C++\ICPC\JXNU Summer Train\10\other\assets\71e5d3230668ba30000126633fe3cd58ed5558e0.png) 模 998 244 353，其中 *l*, *r* 在每次操作时会给定。

总共有 *q* 次操作，请你在维护序列的过程中，输出第二种操作所询问的答案。**注意需要取模。**

# 思路

线段树

我们先想一个比较暴力的线段树实现办法，维护一下区间元素的平方的和，直接点修区查，暴力对区间里面的每个元素进行修改，但是我觉得这个做法应该是不会被放过去的，所以考虑优化

首先我们考虑一下这个区间按位与操作，我们知道与操作的结果一定是不增加，所以要么不变，要么减小，这就给我们下面的做法提供了思路。

对于一个区间里面所有数，我们拆位来看，我们只关心他们有$1$的位，而不关心他们的$0$位，因为只有原本是$1$的位对上了区间修改的$x$的$0$位，说明这个区间里面有元素需要被按位与，我们才需要对这个区间进行修改，那么我们如何维护区间里面所有元素的$1$位呢，很明显按位或可以做到这一点

维护区间或$ors$ 以及 区间答案$s$

区间修改：

每次往下找的时候，我们考虑当前区间或$ors$按位与$x$之后是否还是原来的$ors$，如果我们发现符合，就说明不需要再往下递归下去。否则的话，我们就对这个区间继续往下找，直到按位与$x$对区间或不产生影响。如果到最后区间只剩下一个元素的时候还是会被按位与$x$影响，我们修改完这个元素之后再往上做更新

# 代码

```c++
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 450000;
const i64 INF = 1e18, mod = 998244353;
i64 a[N];
int n, q;

struct Info {
    int l;
    int r;
    i64 s;
    i64 ors;
} seg[N << 2];

void build(int id = 1, int l = 1, int r = n) {
    seg[id].l = l, seg[id].r = r;
    if (l == r) {
        seg[id].s = a[r] * a[r] % mod;
        seg[id].ors = a[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id].s = (seg[id << 1].s + seg[id << 1 | 1].s) % mod;
    seg[id].ors = seg[id << 1].ors | seg[id << 1 | 1].ors;
}

void rangeApply(int id, int l, int r, int val) {
    if (seg[id].ors == (val & seg[id].ors)) return;
    if (seg[id].l > r or seg[id].r < l) return;
    if (seg[id].l == seg[id].r) {
        seg[id].ors &= val;
        seg[id].s = seg[id].ors * seg[id].ors % mod;
        return;
    }
    rangeApply(id << 1, l, r, val);
    rangeApply(id << 1 | 1, l, r, val);
    seg[id].s = (seg[id << 1].s + seg[id << 1 | 1].s) % mod;
    seg[id].ors = seg[id << 1].ors | seg[id << 1 | 1].ors;
}

void rangeApply(int l, int r, int val) {
    rangeApply(1, l, r, val);
    return;
}

i64 rangeQuery(int id, int l, int r) {
    if (seg[id].l > r or seg[id].r < l) return 0LL;
    if (seg[id].l == l and seg[id].r == r) return seg[id].s;
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (r <= mid) return rangeQuery(id << 1, l, r);
    else if (l > mid) return rangeQuery(id << 1 | 1, l, r);
    return (rangeQuery(id << 1, l, mid) % mod + rangeQuery(id << 1 | 1, mid + 1, r) % mod) % mod;
}

i64 rangeQuery(int l, int r) { return rangeQuery(1, l, r); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    cin >> q;
    while (q--) {
        int o, l, r, x;
        cin >> o;
        if (o == 1) {
            cin >> l >> r >> x;
            rangeApply(l, r, x);
        } else {
            cin >> l >> r;
            cout << rangeQuery(l, r) << '\n';
        }
    }

    return 0;
}
```


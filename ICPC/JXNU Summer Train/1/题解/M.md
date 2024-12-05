# 题意

多组数据,定义$f_i$表示$i$最少可以由几个质数组成,例如$f_2=1$,$f_6=2$,每次询问给你一个$n$,问你$\sum_{i=2}^{n}f_i$的值

# 方法

哥德巴赫猜想:任意一个大于$2$的偶数都能由两个质数组成

因此,对于$i$,我们首先考虑它本身是否为质数,若为质数,$f_i=1$,否则我们讨论$i$是奇数还是偶数,如果是偶数,则$f_i=2$;如果是奇数,我们考虑$i-2$是否是质数,如果是质数,就能由$2+(i-2)$这两个质数组成,即$f_i=2$,否则我们可以先分出来一个$3$,然后$i-3$一定是一个偶数,我们已知一个非$2$的偶数一定可以由$2$个质数组成,而且这个偶数一定不等于$2$(因为如果$i-3=2$,则$i=5$,不符合$i-2$不为质数的条件),故此时$f_i=3$,然后对$f$前缀和一下即可

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 1E7 + 10;
vector<int> minp, primes, f(N);
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void Solution(int T) {
    int n;
    cin >> n;
    cout << f[n] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    sieve(N);
    for (int i = 2; i < N; i++) {
        if (minp[i] == i) {
            f[i] = 1;
        } else {
            if (i & 1) {
                if (minp[i - 2] == i - 2) {
                    f[i] = 2;
                } else {
                    f[i] = 3;
                }
            } else {
                f[i] = 2;
            }
        }
    }
    for (int i = 3; i < N; i++) f[i] += f[i - 1];

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
```

[题目链接](https://codeforces.com/gym/536487/problem/M)
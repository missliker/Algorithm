# 题意

给你$n$个三维向量,每个向量标记为$x=(a,b,c)$,$a,b,c$均为整数,让你从$1$到$n$中选择一个子集$S$,让你$\max(\sum_i^{S}|a_i|+|b_i|+|c_i|)$

# 方法

三个元素的向量,从对答案的贡献考虑,最多有$8$种状态,比如第一个值为正,第二个值为负,第三个值为正的类型,我们分类讨论,直接状态压缩枚举$[0,8)$,当二进制位上为$1$表示这个位置是正态,为$0$表示是负态,当其和$s$是正数的时候,代表能为这种状态的和提供正贡献,我们应该加上,最后比较这$8$种状态谁最大即可

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    auto go = [&](i64 f) {
        if (f == 0) return -1;
        return 1;
    };

    i64 ans = 0;
    for (int k = 0; k < (1 << 3); k++) {
        i64 tmp = 0;
        i64 fc = k & 1, fb = k >> 1 & 1, fa = k >> 2 & 1;
        fa = go(fa), fb = go(fb), fc = go(fc);
        for (int i = 0; i < n; i++) {
            i64 s = fa * a[i] + fb * b[i] + fc * c[i];
            if (s >= 0) tmp += s;
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';

    return 0;
}
```

[题目链接](https://codeforces.com/gym/536487/problem/I)
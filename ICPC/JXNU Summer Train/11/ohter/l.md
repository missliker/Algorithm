# 题意

一份代码有n行，其中m行代码有bug，并且已经知道这m行代码的具体位置，每次调试可以选择到第i行，然后程序从第一行跑到第i行，需要i秒，然后一次性修复这i行bug，假设存在x个bug，就需要$x^4$秒来修复这些bug，问你最短要多少秒修复完所有的bug

# 思路

看到这个题意给人的第一反应其实就是dp，一开始的dp思路是dp[i]表示前i行需要的最短时间，那么很容易写出一个$n^2$的dp转移：
$$
dp[i]=min(dp[j]+i+{(s[i]-s[j])}^4)
$$
s[i]表示从第1行到第i行有多少个bug

但是这个转移很明显不合格，我们考虑与其每一行都转移，不如只去转移有bug的行，当前这行是存在bug的，从上一个有bug的行转移过来，这样可以优化到$m^2$，但是依旧不合格

这个时候，我们需要注意到这个四次方，四次方是一个很危险的指数爆炸，假如我有40个bug，我如果想一次修改，那么最少需要$40+40^4$，但是如果我先修改一次，然后再去修改剩下的39个bug，我们发现大约是需要$1+1^4+40+39^4$，这种就已经少于我们直接一次修改40个bug了，这就为我们的优化提供了方向，我们只枚举m行bug，然后从前面40个bug行转移过来，这样复杂度就只有$O(40m)$了，完全足够通过此题

# 代码

```c++
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    vector<i64> dp(m + 1, 1E18 + 10);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i - 1; j >= max(0, i - 40); j--) {
            i64 add = pow(i64(i - j), 4);
            dp[i] = min(dp[i], dp[j] + a[i] + add);
        }
    }
    cout << dp[m] << '\n';

    return 0;
}
```


# 题意

签到题,给你一个长度为$n$的数组,给你一个长度$k$,让你从左到右算长度为$k$的子数组的和,进行一下单位转化

# 方法

维护一个前缀和即可

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(6);

    int n, k;
    cin >> n >> k;
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
        if (i >= k) {
            double ans = 1.0 * (s[i] - s[i - k]) / k;
            if (ans >= 1024) {
                cout << ans / 1024 << " MiBps\n";
            } else {
                cout << ans << " KiBps\n";
            }
        }
    }

    return 0;
}
```

[题目链接](https://codeforces.com/gym/105161/problem/F)
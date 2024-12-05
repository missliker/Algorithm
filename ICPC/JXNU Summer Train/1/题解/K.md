# 题意

签到题,比大小即可

# 方法

左等于右输出“even even seven EIeven.”,左大于右输出"orz teralem is the king!",否则输出"orz overflowker is the king!"

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int T, O;
    cin >> T >> O;
    if (T == O) {
        cout << "even even seven EIeven.\n";
    } else if (T > O) {
        cout << "orz teralem is the king!\n";
    } else {
        cout << "orz overflowker is the king!\n";
    }

    return 0;
}
```

[题目链接](https://codeforces.com/gym/536487/problem/K)
# 题意

题意是给你$n$个木板,给你一个数组$a$表示第$i$个木板的高度,你可以使用一次魔法,让一块木板的一部分拼接到另一块木板上问你木桶最多能放多高的水,其实就是让你求木板的最小值最大能是多少.

# 方法1

直接二分,注意题意要求四舍五入保留一位小数,wa了一发是因为乱用了round

首先,cout<<fixed<<setprecision(1)表示的是四舍五入保留1位小数

其次,round是对小数部分四舍五入,保留到整数部分,例如round(3.91)=4

有关fixed和cetprecision函数的具体使用:[链接](https://blog.csdn.net/Dakin_/article/details/80859193)

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(1);
 
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    double l = 0, r = *max_element(a.begin() + 1, a.end());
 
    auto check = [&](double x) -> bool {
        int cnt = 0, need = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < x) {
                cnt++;
                need = a[i];
            }
        }
        if (cnt > 1) return false;
        if (cnt == 0) return true;
        if (need + *max_element(a.begin() + 1, a.end()) >= 2 * x) return true;
        return false;
    };
 
    while (r - l >= 1E-6) {
        double mid = (l + r) / 2.0;
        if (check(mid)) l = mid;
        else r = mid;
    }
    double ans = r;
    cout << ans << '\n';
 
    return 0;
}
```



# 方法2

因为肯定是最长的去给最短的补,所以可以先排序,然后直接算出结果,假设是下标从0开始,具体公式如下:

$\min\left(a_1, \frac{a.front() + a.back()}{2}\right)$

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(1);

    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& i : a) cin >> i;
    if (n == 1) {
        cout << a.front() << '\n';
        return 0;
    }
    ranges::sort(a.begin(), a.end());
    cout << min(1.0 * a[1], (a.front() + a.back()) / 2.0) << '\n';

    return 0;
}
```

[题目链接](https://codeforces.com/gym/536487/problem/A)
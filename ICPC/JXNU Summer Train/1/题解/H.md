# 题意

多组数据,题意是给你街道的长度$n$,灯的个数$k$,亮度系数$d$,任意一个位置的亮度的计算方式为:若该位置附近的灯与该位置的距离为$r$,则亮度为$\frac{d}{r^2}$,一个位置的亮度最多由其左边最近的路灯和右边最近的路灯相加组成,问最暗的地方最大亮度为多少

# 方法

其实是解方程组,假设第一个灯到最后一个灯占据的长度为$L$,第一个灯与$0$的距离为$x$,显然最后一个灯与$n$的距离也为$x$,故有以下方程组:

$$\begin{equation*}
     \begin{cases}
         L+2x=n \\
         \frac{d}{x^2}=\frac{2d}{{(\frac{L}{2(k-1)}})^2} \\ 
     \end{cases}
 \end{equation*}$$

化简得到一个关于$x$的一元二次方程

$[4-8(k-1)^2]x^2-4nx+n^2=0$

理论分析一下该型为$ax^2+bx+c=0$的一元二次方程

$a$一定小于$0$,故求根公式直接取$x=\frac{-b-\sqrt{\Delta}}{2a}$,其中$\Delta=b^2-4ac$

剩下的就是用求根公式得到$x$,然后最终答案为$\frac{d}{x^2}$

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;

void Solution(int T) {
    i64 n, k, d;
    cin >> n >> k >> d;
    ld a = 4.0 - 8.0 * (k - 1) * (k - 1), b = -4.0 * n, c = 1.0 * n * n;
    ld r = (-b - sqrtl(b * b - 4.0 * a * c)) / (a * 2.0);
    ld ans = ld(1.0) * d / (r * r);
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
```

[题目链接](https://codeforces.com/gym/536487/problem/H)
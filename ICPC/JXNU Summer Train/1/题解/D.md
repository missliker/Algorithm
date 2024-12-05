# 题意

给你$n$条线段,你可以任选一些线段,设这个集合为$S$,假设按这种方案选线段的代价为所有经过的格子的个数,即假设选取线段$[1,5]$,代价为$4$,选取线段为$[1,3]$和$[4,7]$,代价为$2+3=5$,问你所有方案的代价和为多少,答案需要对$998244353$取模

# 方法

考虑每个格子对代价的贡献,假设有$k$条线段经过了该格子,对于这$k$条线段,我们考虑选或者不选,只要有一条选了,则该方案就能在该格子上产生贡献,则我们有$2^k-1$种状态是合法的,但是这里只考虑了这$k$条经过了该点的线段,还有$n-k$条没经过这个格子的线段,事实上,这$n-k$条线段我们选或不选都是无所谓的,所以这个格子能产生贡献的方案数其实是$(2^k-1)\cdot2^{n-k}$,但是做到这里还没完,我们发现,线段的右端点是可以到$10^9$的数据范围的,我们很自然的可以想到离散化,对于连着的并且都有$k$条线段经过的区间做整体的计算,那么这一段对答案的贡献就是$(2^k-1)\cdot 2^{n-k}\cdot len$,$len$表示区间长度,使用map差分就能很轻松的计算每个区段会被多少条线段经过

关于每个区段上有多少条线段经过,我们可以只在map上差分,但是先不前缀和,然后用一个变量指针$lst$表示上一个端点,,考虑到$1\le{l,r}\le{10^9}$,$lst$的初始值就可以设置为$0$,用一个变量$k$表示以当前端点为右端点,以上一个端点为左端点,这个区段上经过的线段数,以$[now,add]$形式遍历我们的map,当$lst=0$时,我们直接让$lst=now,k=k+add$,然后直接$continue$,在下面就是$lst$不为$0$的情况,我们需要先对答案加上我们的那个式子,即$ans=ans+(2^k-1)\cdot 2^{n-k}\cdot (now-lst)$

然后按$lst=now,k=k+add$更新$lst$和$k$即可

# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) { res *= a; }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) { res += p; }
    return res;
}
template <i64 P>
struct MLong {
    i64 x;
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x) : x{norm(x % getMod())} {}

    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) { Mod = Mod_; }
    constexpr i64 norm(i64 x) const {
        if (x < 0) { x += getMod(); }
        if (x >= getMod()) { x -= getMod(); }
        return x;
    }
    constexpr i64 val() const { return x; }
    explicit constexpr operator i64() const { return x; }
    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong& operator*=(MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong& operator+=(MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong& operator-=(MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong& operator/=(MLong rhs) & { return *this *= rhs.inv(); }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MLong& a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MLong& a) { return os << a.val(); }
    friend constexpr bool operator==(MLong lhs, MLong rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MLong lhs, MLong rhs) { return lhs.val() != rhs.val(); }
};

template <>
i64 MLong<0LL>::Mod = i64(1e18) + 9;

template <int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}

    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const {
        if (x < 0) { x += getMod(); }
        if (x >= getMod()) { x -= getMod(); }
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt& operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt& operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt& operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt& operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};

template <>
int MInt<0>::Mod = 998244353;

template <int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    map<int, i64> mp;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        mp[l]++, mp[r]--;
    }

    int lst = 0;
    Z ans = 0;
    i64 k = 0;
    for (auto& [x, y] : mp) {
        if (!lst) {
            lst = x;
            k += y;
            continue;
        }
        // cerr << "lst : " << lst << ' ' << "now : " << x << ' ' << "k : " << k << endl;
        ans += (power(Z(2), k) - 1) * (x - lst) * power(Z(2), n - k);
        k += y;
        lst = x;
    }
    cout << ans << '\n';

    return 0;
}
```

[题目链接](https://codeforces.com/gym/536487/problem/D)
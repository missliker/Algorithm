#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    const int N = 1E5;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (st.find(i) != st.end()) continue;
        int g = -1;
        for (int p = i * 2; p <= N; p += i) {
            if (st.find(p) == st.end()) continue;
            if (g == -1) {
                g = p / i;
            } else {
                g = gcd(g, p / i);
                if (g == 1) {
                    ans++;
                    st.insert(i);
                    break;
                }
            }
        }
    }
    cout << ((ans & 1) ? "dXqwq" : "Haitang") << '\n';
}

/*
一个数i是不是x和y的最大公因数，就看gcd(x/i, y/i)是否等于1
等于1就说明i是这两个数的最大公因数

当我们发现一个数i没有被加入集合中的时候，我们就看这个i是否能被加入集合
我们就需要去找他的x和y，直接logN的去枚举i的倍数，这些倍数要求已经在集合里
看符合要求的倍数是否有gcd(x/i, y/i)=1,有就说明这个i应该被加入集合中

最终看加入了多少个元素，如果加入了奇数个，就说明dx赢了，否则海棠赢
*/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}
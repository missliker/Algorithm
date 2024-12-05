# 题意

一棵由 n 个节点组成的无根树，节点编号从 1 到 n，每个节点有一个正整数点权。当且仅当该节点作为根时，对于除根节点以外的所有节点，其点权都不小于其父亲节点的点权的1/2，这个节点被认为是一个美丽节点。 请你计算出有多少个节点是美丽节点。

# 思路

我们发现虽然这个题是一个树，连的是无向边，但是根据这个美丽节点的定义，我们发现这些边其实是有方向性的，这里我们用样例的几个图来展示：

第二个样例：

![b6f52de9bfc3c62ac703634da01626a4](D:\C++\ICPC\JXNU Summer Train\11\ohter\assets\b6f52de9bfc3c62ac703634da01626a4.jpg)

第三个样例：

![9341e6914da210942c378ef7f805daa6](D:\C++\ICPC\JXNU Summer Train\11\ohter\assets\9341e6914da210942c378ef7f805daa6.jpg)

由此我们可以观察到，有的点就不可能是美丽节点，比如例三的点3，而有的点是可以相互连通的，我们把这些相互连通的点进行缩点，最终就只会得到一个有向无环图，最终我们找到一个点，这个点的入度是0，这个点所代表的所有点都是合法的美丽节点，但是如果有多个块的入读为0，那么就说明这个树里面没有一个点能到所有的点，这个时候美丽节点的个数为0

具体缩点我们可以直接使用并查集来完成这个操作，并且在处理边的时候，直接处理成有向边，该缩点缩点，然后处理一下每个点的入度，最后跑一遍循环，看一下缩点是不是入度为0，如果是0就记一下个数，统计一下这个缩点里面包含了多少个点。只有入度为0的缩点只有一个的情况下，这个缩点包含的点的个数就是美丽节点的个数，否则为0.

# 代码

```c++
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<vector<int>> adj;
constexpr int N = 1E5 + 10;
int a[N], in[N], p[N], cnt[N];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    cnt[u] += cnt[v];
    p[v] = u;
    return true;
}

void Solution(int T) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
        cnt[i] = 1;
    }
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (a[u] * 2 >= a[v] and a[v] * 2 >= a[u]) {
            merge(u, v);
            continue;
        }
        if (a[u] * 2 >= a[v]) {
            adj[v].emplace_back(u);
        } else if (a[v] * 2 >= a[u]) {
            adj[u].emplace_back(v);
        }
    }

    for (int i = 1; i <= n; i++) in[i] = 0;
    for (int i = 1; i <= n; i++) {
        int u = i;
        for (auto v : adj[u]) {
            u = find(u), v = find(v);
            if (u == v) continue;
            in[v]++;
        }
    }

    int ans = 0, tree = 0;
    for (int u = 1; u <= n; u++) {
        if (u != find(u) or in[u]) continue;
        tree++;
        ans += cnt[u];
    }
    if (tree > 1) ans = 0;
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


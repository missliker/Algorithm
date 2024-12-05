#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct State {
    int len, link;
    map<char, int> next;
};

vector<State> st;
vector<int> dp, sz;
int last;

void sam_init() {
    st.push_back({0, -1});
    last = 0;
}

void sam_extend(char c) {
    int cur = st.size();
    st.push_back({st[last].len + 1, 0});
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = st.size();
            st.push_back({st[p].len + 1, st[q].link, st[q].next});
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void calc_occurrences() {
    dp.resize(st.size(), 0);
    sz.resize(st.size(), 0);
    for (int i = 0; i < st.size(); i++) { sz[i] = 1; }
    vector<int> order;
    vector<int> in_degree(st.size(), 0);
    for (auto& state : st) {
        for (auto& edge : state.next) { in_degree[edge.second]++; }
    }
    queue<int> q;
    for (int i = 0; i < st.size(); i++) {
        if (in_degree[i] == 0) { q.push(i); }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto& edge : st[u].next) {
            int v = edge.second;
            if (--in_degree[v] == 0) { q.push(v); }
        }
    }
    reverse(order.begin(), order.end());
    for (int u : order) {
        if (st[u].link != -1) { sz[st[u].link] += sz[u]; }
    }
    for (int i = 0; i < st.size(); i++) { dp[i] = sz[i]; }
}

int find_occurrences(const string& sub) {
    int current_state = 0;
    for (char c : sub) {
        if (!st[current_state].next.count(c)) { return 0; }
        current_state = st[current_state].next[c];
    }
    return dp[current_state];
}

int main() {
    string S = "missisippi";
    vector<string> queries = {"i", "s", "a", "is", "missisippi"};

    // 构建后缀自动机
    sam_init();
    for (char c : S) { sam_extend(c); }

    // 计算每个状态对应的子串出现次数
    calc_occurrences();

    // 处理查询
    for (const string& query : queries) { cout << "Occurrences of '" << query << "': " << find_occurrences(query) << endl; }

    return 0;
}

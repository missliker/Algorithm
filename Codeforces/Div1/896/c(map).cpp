#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

struct range_param {
    std::size_t begin{};
    std::size_t end{};
    std::size_t step{1};
};
auto range(std::size_t begin, std::size_t end, std::size_t step = 1) { return views::iota(begin, end) | views::stride(step); }
auto range(std::size_t end) { return views::iota(0UZ, end) | views::stride(1); }
auto range(range_param param) { return range(param.begin, param.end, param.step); }

bool chmax(auto& x, auto&& y) { return (x < y) ? (x = y, true) : false; }
bool chmin(auto& x, auto&& y) { return (x > y) ? (x = y, true) : false; }

template <typename T>
auto max(const T& container) {
    if constexpr (not std::ranges::range<T>) {
        return container;
    } else {
        using U = decltype(max(*std::begin(container)));
        U res = numeric_limits<U>::lowest();
        for (const auto& sub_container : container) res = std::max(res, max(sub_container));
        return res;
    }
}

template <typename T>
auto min(const T& container) {
    if constexpr (not std::ranges::range<T>) {
        return container;
    } else {
        using U = decltype(min(*std::begin(container)));
        U res = std::numeric_limits<U>::max();
        for (const auto& sub_container : container) res = std::min(res, min(sub_container));
        return res;
    }
}

template <typename T>
auto sum(const T& container) {
    if constexpr (not std::ranges::range<T>) {
        return container;
    } else {
        decltype(sum(*std::begin(container))) res = 0;
        for (const auto& sub_container : container) res += sum(sub_container);
        return res;
    }
}

auto reversed(auto a) {
    std::ranges::reverse(a);
    return a;
}

auto shuffled(auto a) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    std::ranges::shuffle(a, rng);
    return a;
}

auto uniqued(auto a) {
    std::ranges::sort(a);
    a.erase(std::unique(a.begin(), a.end()), a.end());
    return a;
}

template <typename... Args>
auto sorted(auto a, Args&&... args) {
    std::ranges::sort(a, forward<Args>(args)...);
    return a;
}

template <typename T>
auto make_vector(T x) {
    return x;
}

template <typename T1, typename T2, typename... Args>
auto make_vector(T1 m, T2 n, Args... arg) {
    return vector(m, make_vector(n, arg...));
}

template <typename T>
T transposed(T a) {
    if (a.empty()) return a;
    std::size_t m = a.size(), n = a[0].size();
    T b(n, vector<typename T::value_type::value_type>(m));
    for (std::size_t j : range(n)) {
        for (std::size_t i : range(m)) {
            b[j][i] = a[i][j];
        }
    }
    return b;
}

template <typename Tuple, typename F, std::size_t... N>
void TupleCall(Tuple& t, F&& f, std::index_sequence<N...>) {
    (f(get<N>(t)), ...);
}

template <typename... Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& t) {
    TupleCall(t, [&](auto&& a) { out << a << ' '; }, make_index_sequence<sizeof...(Args)>{});
    return out;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& t) {
    return out << t.first << ' ' << t.second;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    for (const auto& elem : v) out << elem << ' ';
    return out;
}

template <typename T, typename... Args>
void print(const T& t, const Args&... args) {
    std::cout << t;
    if constexpr (sizeof...(args)) {
        std::cout << ' ';
        print(args...);
    } else {
        std::cout << '\n';
    }
}

template <typename T = i64>
auto rd() {
    T tmp;
    std::cin >> tmp;
    return tmp;
}

template <std::size_t N, typename T = i64>
auto rd() {
    std::array<T, N> res;
    for (auto& x : res) std::cin >> x;
    return res;
}

template <typename T = i64>
auto rd(std::size_t n, std::size_t off = 0) {
    std::vector<T> v(off + n);
    for (std::size_t i : range(off, off + n)) std::cin >> v[i];
    return v;
}

constexpr i64 mod = 998244353;
auto power(auto a, i64 b, i64 p = mod) {
    i64 res = 1;
    for (; b; a = 1LL * a * a % p, b /= 2) {
        if (b % 2) res = (res * a) % p;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    auto [n, m, seed, vmax] = rd<4>();
    auto a = make_vector(n, 0LL);
    map<int, i64> f;

    auto rnd = [&]() {
        i64 ret = seed;
        seed = (seed * 7 + 13) % 1000000007;
        return ret;
    };

    for (auto i : range(n)) {
        a[i] = rnd() % vmax + 1;
        f[i] = a[i];
    }
    f[n] = -1;
    debug(f);

    auto split = [&](int i) {
        auto it = prev(f.upper_bound(i));
        if (it->first != i) f[i] = it->second;
    };

    while (m--) {
        auto o = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
        if (l > r) swap(l, r);
        l--;
        auto x = (o == 3 ? rnd() % (r - l) : rnd() % vmax + 1);
        split(l), split(r);
        if (o == 1) {
            for (auto i = f.find(l); i->first != r; i++) i->second += x;
        } else if (o == 2) {
            for (auto i = f.find(l); i->first != r; i = f.erase(i));
            f[l] = x;
        } else if (o == 3) {
            auto v = make_vector(0, array<i64, 2>{});
            for (auto i = f.find(l); i->first != r; i++) {
                v.push_back({i->second, next(i)->first - i->first});
            }
            ranges::sort(v);
            for (auto [val, pos] : v) {
                if (x < pos) {
                    print(val);
                    break;
                }
                x -= pos;
            }
        } else {
            auto y = rnd() % vmax + 1;
            int ans = 0;
            for (auto i = f.find(l); i->first != r; i++) {
                ans = (ans + power(i->second % y, x, y) * (next(i)->first - i->first)) % y;
            }
            print(ans);
        }
        debug(f);
    }

    return 0;
}
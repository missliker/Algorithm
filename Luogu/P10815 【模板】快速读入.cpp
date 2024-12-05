#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

namespace IO {

char *p1, *p2, buf[1 << 20];
#ifdef missliker
#else
#define getchar() (p1 == p2 and (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
#endif

template <typename T>
T read() {
    T x = 0;
    int f = 1;
    char ch = getchar();
    for (; ch < '0' or ch > '9'; ch = getchar()) {
        if (ch == '-') {
            f = -1;
        }
    }
    for (; ch >= '0' and ch <= '9'; ch = getchar()) {
        x = ((x << 3) + (x << 1)) + (ch - '0');
    }
    return x * f;
}

template <typename T>
void print(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

} // namespace IO

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n = IO::read<int>();
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x = IO::read<int>();
        ans += x;
    }
    IO::print(ans);

    return 0;
}
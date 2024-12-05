# 题意



# 方法





# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Real = double;
constexpr Real eps = 1E-8;

struct Point {
    Real x, y, z;
    Point(const Real& x = 0, const Real& y = 0, const Real& z = 0) : x(x), y(y), z(z) {}
    Point& operator+=(Point p) & {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    Point& operator-=(Point p) & {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
    Point& operator*=(Real v) & {
        x *= v;
        y *= v;
        z *= v;
        return *this;
    }
    Point operator-() const { return Point(-x, -y, -z); }
    friend Point operator+(Point a, Point b) { return a += b; }
    friend Point operator-(Point a, Point b) { return a -= b; }
    friend Point operator*(Point a, Real b) { return a *= b; }
    friend Point operator*(Real a, Point b) { return b *= a; }
};

int sign(const Real& x) { return x < -eps ? -1 : x > eps ? 1 : 0; }

const Real norm(const Point& a) { return a.x * a.x + a.y * a.y + a.z * a.z; }

const Real dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Point cross(const Point& a, const Point& b) { return Point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

struct Line {
    Point a, b;
    Line() = default;
    Line(const Point& a, const Point& b) : a(a), b(b) {}
};

struct Ray : Line {
    Ray() = default;
    using Line::Line;
};

const Point o(0, 0, 0);

using Triangle = array<Point, 3>;
vector<Point> cpoint(const Ray& r, const Triangle& g) {
    Point v = cross(g[1] - g[0], g[2] - g[0]);
    if (dot(v, r.b - r.a) == 0) { return {}; }
    Real k = dot(v, g[0] - r.a) / dot(v, r.b - r.a);

    if (sign(k) < 0) { return {}; }

    Point p = r.a + (r.b - r.a) * k;
    if (dot(v, cross(p - g[0], p - g[1])) < 0 || dot(v, cross(p - g[1], p - g[2])) < 0 || dot(v, cross(p - g[2], p - g[0])) < 0) { return {}; }
    return {p};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;

    vector<array<Point, 3>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            a[i][j] = Point(x, y, z);
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Point p(x, y, z);
        Ray r = Ray(o, p);
        int ans = -1;
        double mn = 1E100;
        for (int j = 0; j < n; j++) {
            auto c = cpoint(r, a[j]);
            if (!c.empty()) {
                double d = norm(c[0]);
                if (d < mn) {
                    mn = d;
                    ans = j;
                }
            }
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}
```

[题目链接](https://codeforces.com/gym/536487/problem/E)
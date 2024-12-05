#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;

namespace Geometry {
constexpr double pi = acos(-1);
constexpr double eps = 1e-8;
// 点与向量
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    bool operator==(const Point a) const { return (fabs(x - a.x) <= eps && fabs(y - a.y) <= eps); }
};

typedef Point Vector;
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }

int sign(double x) {
    // 符号函数
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}
int cmp(double x, double y) {
    // 比较函数
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

double dot(Point a, Point b) {
    // 向量点积
    return a.x * b.x + a.y * b.y;
}

double cross(Point a, Point b) {
    // 向量叉积
    return a.x * b.y - b.x * a.y;
}

double get_length(Point a) {
    // 求向量模长
    return sqrt(dot(a, a));
}

double get_angle(Point a, Point b) {
    // 求A->B的有向角
    return acos(dot(a, b) / get_length(a) / get_length(b));
}

double area(Point a, Point b, Point c) {
    // A为顶点，向量AB与向量AC的叉积，即三角形ABC的面积的2倍（有向）
    return cross(b - a, c - a);
}

Point rotate(Point a, double angle) {
    // 将向量A顺时针旋转angle度
    return Point(a.x * cos(angle) + a.y * sin(angle), -a.x * sin(angle) + a.y * cos(angle));
}

Point get_line_intersection(Point p, Vector v, Point q, Vector w) {
    // 两直线的交点
    // 使用前提，直线必须有交点
    // cross(v, w) == 0则两直线平行或者重合
    Vector u = p - q;
    double t = cross(w, u) / cross(v, w);
    return p + v * t;
}

double distance_to_line(Point p, Point a, Point b) {
    // 点到直线的距离，直线为AB所在直线
    Vector v1 = b - a, v2 = p - a;
    return (cross(v1, v2) / get_length(v1));
}

double distance_to_segment(Point p, Point a, Point b) {
    // 点到线段的距离，线段为线段AB
    if (a == b) return get_length(p - a);

    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if (sign(dot(v1, v2)) < 0) return get_length(v2);
    if (sign(dot(v1, v3)) > 0) return get_length(v3);
    return distance_to_line(p, a, b);
}

Point get_line_projection(Point p, Point a, Point b) {
    // 点在直线上的投影，直线为AB所在直线
    Vector v = b - a;
    return a + v * (dot(v, p - a) / dot(v, v));
}

bool on_segment(Point p, Point a, Point b) {
    // 点是否在线段上
    return sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0;
}

bool segment_intersection(Point a1, Point a2, Point b1, Point b2) {
    // 判断两个线段是否相交
    double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
    double c3 = cross(b2 - b1, a2 - b1), c4 = cross(b2 - b1, a1 - b1);
    return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
}
// 多边形
double polygon_area(Point p[], int n) {
    // 求多边形面积
    double s = 0;
    for (int i = 1; i + 1 < n; i++) s += cross(p[i] - p[0], p[i + 1] - p[i]);
    return s / 2;
}
} // namespace Geometry
using namespace Geometry;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    for (int i = 1; i < n; i++) {
        auto A = p[0], B = p[i];
        map<double, vector<int>> L;
        L[0].push_back(1);
        L[0].push_back(i + 1);

        for (int j = 1; j < n; j++) {
            if (j == i) continue;
            auto dist = distance_to_line(p[j], A, B);
            L[dist].push_back(j + 1);
            if (L.size() > k) break;
        }

        bool ok = true;
        for (auto& [dist, vec] : L) {
            if (vec.size() == 1) {
                ok = false;
                break;
            }
        }
        if (not ok) continue;

        if (L.size() == k) {
            for (auto& [dist, vec] : L) {
                cout << vec.size() << ' ';
                for (auto& i : vec) cout << i << ' ';
                cout << '\n';
            }
            return 0;
        }
    }

    return 0;
}
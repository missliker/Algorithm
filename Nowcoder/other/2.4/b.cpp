#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

const i64 mod = 1000000007;
struct matrix{
  i64 c[3][3];
  matrix(){memset(c, 0, sizeof c);}
} F, A; //F为斐波那契矩阵，A为构造矩阵

matrix operator*(matrix &a, matrix &b){ //矩阵乘法
  matrix t; //临时矩阵
  for(int i=1; i<=2; ++i)
    for(int j=1; j<=2; ++j)
      for(int k=1; k<=2; ++k)
        t.c[i][j]=(t.c[i][j]+a.c[i][k]*b.c[k][j])%mod;
  return t;
}
void quickpow(i64 n){ //快速幂
  F.c[1][1]=F.c[1][2]=1;
  A.c[1][1]=A.c[1][2]=A.c[2][1]=1;
  while(n){
    if(n & 1) F = F*A;
    A = A*A;
    n >>= 1;
  }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    i64 n;
    cin >> n;
    if (n == 1) {
        cout << "2\n";
        return 0;
    }
    if (n == 2) {
        cout << "3\n";
        return 0;
    }
    quickpow(n);
    cout << F.c[1][1] << "\n";
    return 0;
}

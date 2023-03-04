//ID: LRL52  Date: 2022.7.4
//快速傅里叶变换(FFT)，鸽了这么久终于入坑了
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55;
const double Pi = acos(-1.0);
int n, m, tot, rev[N];
struct Complex{
    double x, y;
    inline Complex operator+(const Complex& t)const{
        return {x + t.x, y + t.y};
    }
    inline Complex operator-(const Complex& t)const{
        return {x - t.x, y - t.y};
    }
    inline Complex operator*(const Complex& t)const{
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }
}a[N], b[N];

void FFT(Complex *a, int sign){
    for(int i = 0; i < tot; ++i)
        if(i < rev[i])
            swap(a[i], a[rev[i]]);
    for(int L = 1; L < tot; L <<= 1){
        Complex w1 = {cos(Pi / L), sign * sin(Pi / L)};
        for(int i = 0; i < tot; i += L << 1){
            Complex wk = {1.0, 0.0};
            for(int j = 0; j < L; ++j, wk = wk * w1){
                Complex x = a[i + j], y = wk * a[i + j + L];
                a[i + j] = x + y, a[i + j + L] = x - y;
            }
        }
    }
}

int main() {
#ifdef LRL52
	freopen("FFT.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; ++i) scanf("%lf", &a[i].x);
    for(int i = 0; i <= m; ++i) scanf("%lf", &b[i].x);
    int bit = 0;
    while((1 << bit) < n + m + 1) ++bit;
    tot = 1 << bit;
    for(int i = 0; i < tot; ++i)
        rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
    FFT(a, 1); 
    FFT(b, 1);
    for(int i = 0; i < tot; ++i) a[i] = a[i] * b[i];
    FFT(a, -1);
    for(int i = 0; i <= n + m; ++i)
        printf("%d ", (int)(a[i].x / tot + 0.5));
	return 0;
}
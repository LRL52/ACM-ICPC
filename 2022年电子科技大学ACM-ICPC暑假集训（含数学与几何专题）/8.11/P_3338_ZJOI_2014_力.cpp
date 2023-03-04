//ID: LRL52  Date: 2022.8.9
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55, M = 2055, inf = 0x3f3f3f3f;
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
}f1[N], f2[N], g[N];

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

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d", &n);
    rep(i, 1, n) scanf("%lf", &f1[i].x);
    f1[0].x = g[0].x = 0.0;
    rep(i, 0, n) f2[i] = f1[n - i];
    rep(i, 1, n) g[i].x = 1.0 / i / i;
    int bit = 0;
    while((1 << bit) < (n << 1)) ++bit;
    tot = 1 << bit;
    for(int i = 0; i < tot; ++i)
        rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
    FFT(f1, 1);
    FFT(f2, 1);
    FFT(g, 1);
    for(int i = 0; i < tot; ++i){
        f1[i] = f1[i] * g[i];
        f2[i] = f2[i] * g[i];
    }
    FFT(f1, -1);
    FFT(f2, -1);
    for(int i = 0; i < tot; ++i){
        f1[i].x = f1[i].x / tot;
        f2[i].x = f2[i].x / tot;
    }
    rep(i, 1, n) printf("%.3lf\n", f1[i].x - f2[n - i].x);
	return 0;
}
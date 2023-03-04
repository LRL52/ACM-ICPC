//ID: LRL52  Date: 2022.7.5
//高精度乘法 (FFT实现)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e6 + 55;
const double Pi = acos(-1.0);
struct Complex{
    double x, y;
    Complex operator+ (const Complex&t)const{
        return {x + t.x, y + t.y};
    }
    Complex operator- (const Complex&t)const{
        return {x - t.x, y - t.y};
    }
    Complex operator* (const Complex&t)const{
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }
}a[N], b[N];
int tot, bit, Ans[N], rev[N];
char s1[N], s2[N];

void FFT(Complex *a, int sign){
    for(int i = 0; i < tot; ++i)
        if(i < rev[i])
            swap(a[i], a[rev[i]]);
    for(int mid = 1; mid < tot; mid <<= 1){
        Complex w1 = {cos(Pi / mid), sign * sin(Pi / mid)};
        for(int i = 0; i < tot; i += mid * 2){
            Complex wk = {1.0, 0.0};
            for(int j = 0; j < mid; ++j, wk = wk * w1){
                Complex x = a[i + j], y = a[i + mid + j] * wk;
                a[i + j] = x + y, a[i + mid + j] = x - y;
            }
        }
    }
}

int main() {
	scanf("%s%s", s1, s2);
    int n = strlen(s1) - 1, m = strlen(s2) - 1;
    for(int i = 0; i <= n; ++i) a[n - i].x = s1[i] - '0';
    for(int i = 0; i <= m; ++i) b[m - i].x = s2[i] - '0';
    while((1 << bit) < n + m + 1) ++bit;
    tot = 1 << bit; //草，因为tot已经定义了全局变量又定义局部变量，导致debug了很久，麻了
    for(int i = 0; i < tot; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    FFT(a, 1), FFT(b, 1);
    for(int i = 0; i < tot; ++i) a[i] = a[i] * b[i];
    FFT(a, -1);
    int res = 0, p = 0;
    for(int i = 0; i <= n + m || res; ++i){
        res += (int)(a[i].x / tot + 0.5);
        Ans[++p] = res % 10;
        res /= 10;
    }
    for(int i = p; i >= 1; --i) printf("%d", Ans[i]);
	return 0;
}

//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define double long double
#define int long long
const double eps = 1e-8;

double sqr(double x){return x * x;}
int sqr(int x){return x * x;}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int ox, oy, oz, r, sx, sy, sz, ex, ey, ez;
    int Task; rd(Task);
    while(Task--){
        rd(ox), rd(oy), rd(oz), rd(r);
        rd(sx), rd(sy), rd(sz), rd(ex), rd(ey), rd(ez);
        if(sx == ex && sy == ey && sz == ez){
            puts("0.00000000");
            continue;
        }
        int a = ex - sx, b = ey - sy, c = ez - sz;
        int d = ox - sx, e = oy - sy, f = oz - sz;
        //printf("a = %lld b = %lld c = %lld d = %lld e = %lld f = %lld\n", a, b, c, d, e, f);
        double D = sqrt(sqr(b * f - e * c) + sqr(c * d - a * f) + sqr(a * e - b * d));
        //printf("D = %.3Lf\n", D); 
        D /= sqrt(sqr(a) + sqr(b) + sqr(c));
        double ST = sqrt(sqr(sx - ex) + sqr(sy - ey) + sqr(sz - ez));
        double SO = sqrt(sqr(sx - ox) + sqr(sy - oy) + sqr(sz - oz));
        double TO = sqrt(sqr(ex - ox) + sqr(ey - oy) + sqr(ez - oz));
        if((ex - sx) * (ox - sx) + (ey - sy) * (oy - sy) + (ez - sz) * (oz - sz) < 0 ||
           (sx - ex) * (ox - ex) + (sy - ey) * (oy - ey) + (sz - ez) * (oz - ez) < 0){
               D = min(SO, TO);
           }
        if(D >= r){
            printf("%.8Lf\n", ST);
            continue;
        }
        double d1 = sqrt(sqr(sx - ox) + sqr(sy - oy) + sqr(sz - oz) - r * r);
        double d2 = sqrt(sqr(ex - ox) + sqr(ey - oy) + sqr(ez - oz) - r * r);
        double cosval = (sqr(SO) + sqr(TO) - sqr(ST)) / (2.0F * SO * TO);
        double alpha = acos(cosval);
        double beta1 = acos(r / SO);
        double beta2 = acos(r / TO);
        double theta = alpha - beta1 - beta2;
        double d3 = r * theta;
        printf("%.8Lf\n", d1 + d2 + d3);
    }
	return 0;
}
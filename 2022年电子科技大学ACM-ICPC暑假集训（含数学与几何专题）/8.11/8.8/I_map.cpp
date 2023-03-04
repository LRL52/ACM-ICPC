//ID: LRL52  Date: 2022.8.8
#pra
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
struct Comp{
    double x, y;
    Comp(double _x = 0.0F, double _y = 0.0F){
        x = _x, y = _y;
    }
    Comp operator+(const Comp&t){
        return {x + t.x, y + t.y};
    }
    Comp operator-(const Comp&t){
        return {x - t.x, y - t.y};
    }
    Comp operator*(const Comp&t){
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }
    Comp operator*(const double&t){
        return {x * t, y * t};
    }
    Comp operator/(const double&k){
        return {x / k, y / k};
    }  
}A[4], a[4];

Comp z_(const Comp&t){
    return Comp(t.x, -t.y);
}

double len2(const Comp&t){
    return t.x * t.x + t.y * t.y;
}

Comp operator/(Comp &t1, Comp &t2){
    Comp res = t1 * z_(t2);
    double len = len2(t2);
    return {res.x / len, res.y / len};
}
    

signed main() {
#ifdef LRL52
	freopen("I.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		int x, y;
        for(int i = 0; i < 4; ++i){
            rd(x), rd(y);
            A[i].x = x, A[i].y = y;
        }
        for(int i = 0; i < 4; ++i){
            rd(x), rd(y);
            a[i].x = x, a[i].y = y;
        }
        Comp DA = A[0] - A[3], da = a[0] - a[3];
        double k = sqrt(len2(da) / len2(DA));
        double costheta = (da.x * DA.x + da.y * DA.y) / sqrt(len2(da) * len2(DA));
        double sintheta = sqrt(1 - costheta * costheta);
        if(DA.x * da.y - da.x * DA.y < 0.0)
            sintheta = -sintheta;
        Comp e = Comp(costheta, sintheta);
        Comp res1 = A[3] * e * k - a[3];
        Comp res2 = e * k - Comp(1.0F, 0.0F);
        Comp res = res1 / res2;
        printf("%.6Lf %.6Lf\n", res.x, res.y);
	}
	return 0;
}
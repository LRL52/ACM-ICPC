//ID: LRL52  Date: 2022.8.16
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
const double Pi = acos(-1.0);

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	double a, b, x;
    scanf("%lf%lf%lf", &a, &b, &x);
    double h = x / a / a, alpha;
    if(h > b / 2.0)
        alpha = a / 2.0 / (b - h);
    else
        alpha = 2.0 * a * h / b / b;
    printf("%.10lf\n", (90.0 - atan(alpha) * 180.0 / Pi));
	return 0;
}
//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const double Pi = acos(-1.0);

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    double a, b, d;
	scanf("%lf%lf%lf", &a, &b, &d);
    d = d * Pi / 180.0;
    double x = a * cos(d) - b * sin(d);
    double y = a * sin(d) + b * cos(d);
    printf("%.8lf %.8lf\n", x, y);
	return 0;
}

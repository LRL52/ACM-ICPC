//ID: LRL52  Date: 2022.7.22
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 100055, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
const double eps = 1e-8;
int n, a[N], b[N], c[N], d[N], d1, d2;
int sqr(int x){return x * x;}
double sqr(double x){return x * x;}

int dist(int i){
    return sqr(a[i] - c[i]) + sqr(b[i] - d[i]);
}

double dist2(int i, double t){
    int da = a[i + 1] - a[i], db = b[i + 1] - b[i];
    int dc = c[i + 1] - c[i], dd = d[i + 1] - d[i];
    return sqr(a[i] - c[i] + t * (da - dc)) + sqr(b[i] - d[i] + t * (db - dd));
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(d1), rd(d2);
    rep(i, 1, n){
        rd(a[i]), rd(b[i]);
        rd(c[i]), rd(d[i]);
    }
    int outd = 1, ans = 0;
    if(dist(1) <= d1 * d1) outd = 0, ++ans;
    for(int i = 1; i < n; ++i){
        int nxtd = dist(i + 1);
        if(outd == 0){
            if(nxtd > d2 * d2) outd = 1;
        } else {
            if(nxtd <= d1 * d1) outd = 0, ++ans;
            else{
                int da = a[i + 1] - a[i], db = b[i + 1] - b[i];
                int dc = c[i + 1] - c[i], dd = d[i + 1] - d[i];
                if(da == dc && db == dd) continue;
                double t = (a[i] - c[i]) * (da - dc) + (b[i] - d[i]) * (db - dd);
                t = -t / (sqr(da - dc) + sqr(db - dd));
                if(t >= 0.0 && t <= 1.0){
                    double dm = dist2(i, t);
                    if(dm <= d1 * d1 + eps){
                        ++ans;
                        if(nxtd > d2 * d2) outd = 1;
                        else outd = 0;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
	return 0;
}
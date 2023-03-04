//ID: LRL52  Date: 2022.8.12
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
int n;
double Ans;
struct Node{
    double x, y, z;
}a[N];
const double eps = 1e-6;
inline double sqr(double x){return x * x;}

double calc(double x, double y, double z){
    double res = 0.0;
    rep(i, 1, n){
        res = max(res, sqr(a[i].x - x) + sqr(a[i].y - y) + sqr(a[i].z - z));
    }
    return Ans = res;
}

double SolveZ(double x, double y){
    double l = -100000.0, r = 100000.0, r1 = 0.0, r2 = 0.0;
    while(r - l > eps){
        double lmid = l + (r - l) / 3;
        double rmid = r - (r - l) / 3;
        r1 = calc(x, y, lmid);
        r2 = calc(x, y, rmid);
        if(r1 < r2) r = rmid;
        else l = lmid;
    }
    return min(r1, r2);
}

double SolveY(double x){
    double l = -100000.0, r = 100000.0, r1 = 0.0, r2 = 0.0;
    while(r - l > eps){
        double lmid = l + (r - l) / 3;
        double rmid = r - (r - l) / 3;
        r1 = SolveZ(x, lmid);
        r2 = SolveZ(x, rmid);
        if(r1 < r2) r = rmid;
        else l = lmid;
    }
    return min(r1, r2);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d", &n);
    rep(i, 1, n) scanf("%Lf%Lf%Lf", &a[i].x, &a[i].y, &a[i].z);
    double l = -100000.0, r = 100000.0;
    while(r - l > eps){
        double lmid = l + (r - l) / 3;
        double rmid = r - (r - l) / 3;
        double r1 = SolveY(lmid);
        double r2 = SolveY(rmid);
        if(r1 < r2) r = rmid;
        else l = lmid;
    }
    printf("%.10Lf\n", sqrt(Ans));
	return 0;
}
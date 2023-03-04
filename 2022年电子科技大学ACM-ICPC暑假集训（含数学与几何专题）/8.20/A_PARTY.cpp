//ID: LRL52  Date: 2022.8.20
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
const double eps = 1e-8;
double Ans, L1, L2;
struct Node{
    double x, y;
    Node operator-(const Node&t)const{
        return {x - t.x, y - t.y};
    }
    Node operator+(const Node&t)const{
        return {x + t.x, y + t.y};
    }
    Node operator*(const double&k)const{
        return {x * k, y * k};
    }
}a, b, c, d, e1, e2;
int flag;

double len2(const Node&t){
    return t.x * t.x + t.y * t.y;
}

double calc(double t){
    Node f1 = a + e1 * t;
    Node f2 = c + e2 * t;
    if(t > L2) f2 = d;
    else if(flag) f2 = c;
    double ret = len2(f1 - f2);
    Ans = min(Ans, ret);
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("A2.in", "r", stdin);
#endif
    Ans = 1e25;
	scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
    e1 = b - a, e2 = d - c;
    L1 = sqrt(len2(e1)), L2 = sqrt(len2(e2));
    if(L1 < L2){
        swap(L1, L2);
        swap(a, c); swap(b, d);
        swap(e1, e2);
    }
    double L = max(L1, L2);
    if(L < eps){
        Ans = len2(c - a);
        printf("%.12Lf\n", sqrt(Ans));
        return 0;
    }
    e1.x /= L1, e1.y /= L1;
    if(L2 >= eps) e2.x /= L2, e2.y /= L2;
    else flag = 1;
    double l = 0.0, r = L;
    while(r - l > eps){
        double lmid = l + (r - l) / 3.0;
        double rmid = r - (r - l) / 3.0;
        double res1 = calc(lmid), res2 = calc(rmid);
        if(res1 < res2) r = rmid;
        else l = lmid;
    }
    printf("%.12Lf\n", sqrt(Ans));
	return 0;
}
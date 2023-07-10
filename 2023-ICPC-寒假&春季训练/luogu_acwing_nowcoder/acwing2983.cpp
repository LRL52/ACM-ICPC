//ID: LRL52  Date: 2022.7.14
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, m, Ans[N];
struct Point{
    int x, y;
    Point operator-(const Point&t)const{
        return {x - t.x, y - t.y};
    }
}a[N], b[N];

int cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

int left(Point t, Point u, Point v){
    return cross(t - u, v - u) < 0;
}

int find(int x, int y){
    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(left({x, y}, a[mid], b[mid])) r = mid - 1;
        else l = mid + 1;
    }
    return r;
}

signed main() {
#ifdef LRL52
	freopen("acwing2983.in", "r", stdin);
#endif
    int first = 1, x1, x2, y1, y2;
	while(scanf("%lld", &n) != EOF && n){
        scanf("%lld%lld%lld%lld%lld", &m, &x1, &y1, &x2, &y2);
        int u, l;
        a[0] = {x1, y2}, b[0] = {x1, y1};
        rep(i, 1, n){
            scanf("%lld%lld", &u, &l);
            a[i] = {l, y2}, b[i] = {u, y1};
        }
        rep(i, 0, n) Ans[i] = 0;
        rep(i, 1, m){
            scanf("%lld%lld", &u, &l);
            Ans[find(u, l)]++;
        }
        if(first) first = 0;
        else puts("");
        rep(i, 0, n){
            printf("%lld: %lld\n", i, Ans[i]);
        }
    }
	return 0;
}
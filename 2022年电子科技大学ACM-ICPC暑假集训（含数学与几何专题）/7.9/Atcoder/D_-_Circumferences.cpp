//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, sx, sy, ex, ey;
int X[N], Y[N], R[N], fa[N];

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int sqr(int x){return x * x;}

int cross(int i, int j){
    int d = sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]);
    return d <= sqr(R[i] + R[j]) && d >= sqr(R[i] - R[j]);
}

int oncircle(int i, int x, int y){
    return sqr(x - X[i]) + sqr(y - Y[i]) == sqr(R[i]);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(sx), rd(sy), rd(ex), rd(ey);
    rep(i, 1, n){
        rd(X[i]), rd(Y[i]), rd(R[i]);
    }
    rep(i, 1, n) fa[i] = i;
    int st = 0, ed = 0;
    rep(i, 1, n){
        for(int j = 1; j < i; ++j){
            if(cross(j, i)){
                int f1 = find(i), f2 = find(j);
                fa[f1] = f2;
            }
        }
        if(oncircle(i, sx, sy)) st = i;
        if(oncircle(i, ex, ey)) ed = i;
    }
    if(!st || !ed){
        puts("No");
        return 0;
    }
    find(st) == find(ed) ? puts("Yes") : puts("No");
	return 0;
}

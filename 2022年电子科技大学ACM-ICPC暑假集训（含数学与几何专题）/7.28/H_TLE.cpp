//ID: LRL52  Date: 2022.7.28
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, instk[M << 1], f[M << 1], vis[M << 1], dcnt;
struct Edge{
    int v, nxt;
}e[M << 1];
int head[N], et = 1;

inline void adde(int from, int to){
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

int dfs(int lst, int x, int k){
    if(instk[k]){
        puts("Infinite");
        exit(0);
        assert(0);
    }
    if(vis[k]) return f[k];
    if(++dcnt > 200000){
        assert(0);
    }
    vis[k] = instk[k] = f[k] = 1;
    int maxd = 0;
    ee(i, x){
        //printf("x = %d v = %d i = %d\n", x, e[i].v, i);
        if(i == (k^1)) continue;
        int v = e[i].v;
        maxd = max(maxd, dfs(x, v, i));
    }
    f[k] += maxd, instk[k] = 0;
    //printf("lst = %d x = %d k = %d f = %d\n", lst, x, k, f[k]);
    return f[k];
}

signed main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
    freopen("H_std.out", "w", stdout);
#endif
	rd(n), rd(m); int x, y, z;
    rep(i, 1, m){
        rd(x), rd(y), rd(z);
        if(z == 2) adde(x, y), adde(y, x);
        else adde(x, y), ++et;
    }
    assert(et < (M << 1));
    int ans = 0;
    rep(u, 1, n){
        ee(j, u){
            int v = e[j].v;
            dfs(u, v, j);
            ans = max(ans, f[j]);
        }
    }
    printf("%d\n", ans);
	return 0;
}
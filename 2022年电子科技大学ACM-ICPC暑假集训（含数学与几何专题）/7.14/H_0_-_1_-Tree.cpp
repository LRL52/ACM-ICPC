//ID: LRL52  Date: 2022.7.13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 200055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, f[N], g[N], F[N], G[N], Ans;
struct Edge{
    int v, nxt, w;
}e[N << 1];
int head[N];

inline void adde(int from, int to, int w){
    static int et = 0;
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

void dfs(int x, int far){
    f[x] = g[x] = F[x] = G[x] = 1;
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs(v, x);
        if(e[i].w == 1){
            Ans += G[x] * f[v] + G[v] * f[x];
            f[x] += f[v];
            F[x] += f[v];
            G[x] += G[v];
            
        } else{
            Ans += g[x] * F[v] + g[v] * F[x];
            g[x] += g[v];
            G[x] += g[v];
            F[x] += F[v];
        }
    }   
}


signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int x, y, z;
    rep(i, 1, n - 1){
        rd(x), rd(y), rd(z);
        adde(x, y, z), adde(y, x, z);
    }
    dfs(1, -1);
    printf("%lld\n", Ans);
	return 0;
}
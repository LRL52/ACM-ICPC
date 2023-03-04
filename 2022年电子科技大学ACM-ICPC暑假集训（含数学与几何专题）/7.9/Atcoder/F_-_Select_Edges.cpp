//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, head[N], f[N][2], d[N];
struct Edge{
    int v, nxt, w;
}e[N << 1];
priority_queue<int> q[N];

inline void adde(int from, int to, int w){
    static int et = 0;
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

void dfs(int x, int far){
    f[x][0] = f[x][1] = 0;
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs(v, x);
        f[x][0] += f[v][0];
        f[x][1] += f[v][0];
        if(d[v] > 0 && e[i].w + f[v][1] - f[v][0] > 0) q[x].push(e[i].w + f[v][1] - f[v][0]);
    }
    int sz = q[x].size();
    for(int i = 1; i <= min(d[x], sz); ++i){
        int val = q[x].top(); q[x].pop();
        f[x][0] += val;
        if(i < d[x]) f[x][1] += val;
    }
}

signed main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	rd(n); int x, y, w;
    rep(i, 1, n) rd(d[i]);
    rep(i, 1, n - 1){
        rd(x), rd(y), rd(w);
        adde(x, y, w), adde(y, x, w);
    }
    dfs(1, -1);
    printf("%lld\n", max(f[1][0], f[1][1]));
    //rep(i, 1, n) printf("f[%lld][0] = %lld f[%lld][1] = %lld\n", i, f[i][0], i, f[i][1]);
	return 0;
}

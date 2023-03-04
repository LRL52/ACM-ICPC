//ID: LRL52  Date: 2022.7.5
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, K;
int head[N], dep[N], fa[N], f[N], Size[N], out[N];
struct Node{
    int x, val;
    inline bool operator<(const Node&t)const{
        return val < t.val;
    }
};
priority_queue<Node> q;
struct Edge{
    int v, nxt;
}e[N << 1];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = {to, head[from]};
    head[from] = et;
}

void dfs(int x, int far){
    Size[x] = 1;
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        fa[v] = x, dep[v] = dep[x] + 1;
        ++out[x];
        dfs(v, x);
        Size[x] += Size[v];
        f[x] += Size[v] * dep[v];
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(K); int x, y;
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    dfs(1, -1);
    rep(i, 1, n)
        if(out[i] == 0)
            q.push({i, dep[i]});
    int ans = 0;
    rep(i, 1, K){
        Node qu = q.top(); q.pop();
        x = qu.x;
        //ans += Size[x] * dep[x] - f[x];
        ans += qu.val;
        int par = fa[x];
        if(--out[par] == 0)
            q.push({par, Size[par] * dep[par] - f[par]});
    }
    printf("%lld\n", ans);
	return 0;
}

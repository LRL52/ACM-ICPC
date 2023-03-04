//ID: LRL52  Date: 2022.9.30 ~ 10.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, et, K, fa[N], dep[N], U[N], vis[N];
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x) {
    ee(i, x) {
        int v = e[i].v;
        if(v == fa[x]) continue;
        fa[v] = x, dep[v] = dep[x] + 1;
        dfs(v);
    }
}

void dfs2(int x) {
    //if(vis[x]) return;
    vis[x] = 1;
    ee(i, x) {
        int v = e[i].v;
        if(v == fa[x] || vis[v]) continue;
        dfs2(v);
    }
}

int check(int lim) {
    rep(i, 1, n) vis[i] = 0;
    int tot = 0;
    rep(tt, 1, n){
        int x = U[tt];
        if(vis[x] || dep[x] <= lim) continue;
        int d = dep[x] - lim + 1;
        ++tot;
        while(dep[x] >= d) {
            //vis[x] = 1;
            dfs2(x);
            x = fa[x];
        }
    }
    return tot <= K;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while (Task--) {
		rd(n), rd(K); int x;
        rep(i, 1, n) head[i] = 0;
        et = 0;
        rep(i, 2, n) {
            rd(x);
            adde(x, i), adde(i, x);
        }
        dfs(1);
        auto cmp = [](const int &x, const int &y)->bool {return dep[x] > dep[y];};
        rep(i, 1, n) U[i] = i;
        sort(U + 1, U + n + 1, cmp);
        int l = 1, r = n - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", l);
	}
	return 0;
}
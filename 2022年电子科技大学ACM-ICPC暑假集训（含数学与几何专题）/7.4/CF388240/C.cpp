//ID: LRL52  Date: 2022.7.4
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
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
int n;
int fa[N], vis[N], dep[N], head[N], outq[N];
vector<int> st[N];
struct Edge{
    int v, nxt;
}e[N << 1];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = {to, head[from]};
    head[from] = et;
}

void dfs(int x){
    ee(i, x){
        int v = e[i].v;
        if(v == fa[x]) continue;
        fa[v] = x, dep[v] = dep[x] + 1;
        dfs(v);
    }
}

int main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	rd(n); int x, y;
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    dfs(1); int lstdep = 0, lstfa = 0, p = 0;
    rep(i, 1, n){
        rd(x);
        if(outq[x]){
            puts("No");
            return 0;
        }
        outq[x] = 1;
        if(dep[x] < lstdep || dep[x] > lstdep + 1){
            puts("No");
            return 0;
        }
        if(dep[x] > lstdep) lstdep = dep[x], p = 0;
        if(vis[fa[x]]){
            puts("No");
            return 0;
        }
        if(fa[x] != lstfa){
            vis[lstfa] = 1;
            lstfa = fa[x];
            while(p < st[dep[x] - 1].size() && st[dep[x] - 1][p] != fa[x]) ++p;
            if(p >= st[dep[x] - 1].size()){
                puts("No");
                return 0;
            }
        }
        st[dep[x]].push_back(x);
    }
    puts("Yes");
	return 0;
}
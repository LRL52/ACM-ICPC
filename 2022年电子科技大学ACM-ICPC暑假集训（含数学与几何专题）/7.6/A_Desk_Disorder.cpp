//ID: LRL52  Date: 2022.7.6
//比较巧妙的建图建模
//可以使用并查集或者DFS找环，我为了练习选择了后者
//对于原图的关系进行连边，由题目性质知恰有n个点的出度刚好为1，连边后的图的联通分量只可能是树、环，基环树或前三种情况 + 自环
//只要有自环，方案不会增多；对于树(不含自环)，方案*Size；对于环或基环树(不含自环)，方案*2
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1000055 << 1; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 1e9 + 7;
int n, cir, Size, DFN, loopself;
int dfn[N], head[N];
struct Edge{
    int v, nxt;
}e[N << 1];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x) {
    dfn[x] = ++DFN; ++Size;
    ee(i, x){
        int v = e[i].v;
        if(v == x) loopself = 1; //注意，只要有自环，答案就不会增多，并且其他点可以连到自环上
        if (dfn[v]){
            if (dfn[v] <= dfn[x]) continue;
            cir = 1;
        } else {
            dfs(v);
        }
    }
}

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int x, y;
    rep(i, 1, n){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    int ans = 1;
    rep(i, 1, 2 * n){
        if(dfn[i]) continue;
        cir = Size = loopself = 0;
        dfs(i);
        if(loopself) continue;
        if(cir) ans = 2LL * ans % MOD;
        else ans = 1LL * ans * Size % MOD;
    }
    printf("%d\n", ans);
	return 0;
}

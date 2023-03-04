//ID: LRL52  Date: 2022.5.1
//学习长链剖分优化DP
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
struct Edge{
    int v, nxt;
}e[N << 1];
int n, head[N], Len[N], Ans[N], son[N];
int buf[N];
int *f[N], *pt = buf;

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = {to, head[from]};
    head[from] = et;
}

void dfs(int x, int far){ //Len[x] 以x为起点的长链长度
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs(v, x);
        if(Len[v] + 1 > Len[son[x]])
            son[x] = v;
    }
    Len[x] = Len[son[x]] + 1;
}

inline void chkans(int *f, int &ans, int i){
    if(f[i] > f[ans] || (f[i] == f[ans] && i < ans))
        ans = i;
}

void dfs2(int x, int far){
    f[x][0] = 1, Ans[x] = 0;
    if(son[x]){
        f[son[x]] = f[x] + 1;
        dfs2(son[x], x);
        chkans(f[x], Ans[x], Ans[son[x]] + 1);
    }
    ee(i, x){
        int v = e[i].v;
        if(v == far || v == son[x]) continue;
        f[v] = pt, pt += Len[v];
        dfs2(v, x);
        for(int j = 1; j <= Len[v]; ++j){
            f[x][j] += f[v][j - 1];
            chkans(f[x], Ans[x], j);
        }
    }
}

int main() {
#ifdef LRL52
	freopen("CF1009F.in", "r", stdin);
#endif
	rd(n); int x, y;
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    dfs(1, -1);
    f[1] = pt, pt += Len[1]; 
    dfs2(1, -1);
    rep(i, 1, n) printf("%d\n", Ans[i]);
	return 0;
}
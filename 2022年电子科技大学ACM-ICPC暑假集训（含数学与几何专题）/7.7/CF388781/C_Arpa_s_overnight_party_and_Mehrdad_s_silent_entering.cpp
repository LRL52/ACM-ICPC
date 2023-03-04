//ID: LRL52  Date: 2022.7.7
//二分图染色，BF和GF连边，2i-1和2i连边，且连图后没有偶环，一定有解
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
int head[N], col[N], X[N], Y[N];
struct Edge{
    int v, nxt;
}e[N << 2];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x, int co){
    col[x] = co;
    ee(i, x){
        int v = e[i].v;
        if(!col[v])
            dfs(v, 3 - co);
    }
}

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n){
        rd(X[i]), rd(Y[i]);
        adde(X[i], Y[i]), adde(Y[i], X[i]);
    }
    rep(i, 1, n){
        adde(2 * i - 1, 2 * i);
        adde(2 * i, 2 * i - 1);
    }
    rep(i, 1, 2 * n){
        if(!col[i])
            dfs(i, 1);
    }
    rep(i, 1, n) printf("%d %d\n", col[X[i]], col[Y[i]]); 
	return 0;
}

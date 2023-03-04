//ID: LRL52  Date: 2022.5.10
//二次扫描（换根）的树形DP模板题
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
int a[N], f[N], F[N], head[N];
struct Edge{
    int v, nxt;
}e[N << 1];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = {to, head[from]};
    head[from] = et;
}

void dfs(int x, int far){
    f[x] = a[x];
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs(v, x);
        if(f[v] > 0)
            f[x] += f[v];
    }
}

void dfs2(int x, int far){
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        if(F[x] > 0 && f[v] > 0 && F[x] - f[v] > 0)
            F[v] = F[x];
        else if(F[x] > 0 && f[v] <= 0)
            F[v] = f[v] + F[x];
        else
            F[v] = f[v];
        dfs2(v, x);
    }
}
        

int main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
#endif
    rd(n); int x, y;
    rep(i, 1, n){
        rd(a[i]);
        if(a[i] == 0) a[i] = -1;
    }
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    memset(f, -0x3f, sizeof f);
    memset(F, -0x3f, sizeof F);
    dfs(1, -1);
    F[1] = f[1];
    dfs2(1, -1);
    rep(i, 1, n) printf("%d ", F[i]);
	return 0;
}
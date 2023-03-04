//ID: LRL52  Date: 2022.5.20
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 500055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, head[N], a[N];
long long f[N], g[N];
struct Edge{
    int v, nxt;
}e[N << 1];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = {to, head[from]};
    head[from] = et;
}

void dfs(int x, int far){
    //f[x] 以x为根的最大连通块和（不考虑复位0）
    //g[x] x为根的子树存在结点在无效联通区域内（自然x肯定在无效联通区域内），最大和
    f[x] = a[x];
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs(v, x);
        f[x] += max(f[v], 0LL);
        g[x] += max(f[v], g[v]);
    }
}

int main() {
#ifdef LRL52
	freopen("R.in", "r", stdin);
#endif
    rd(n); int x;
    rep(i, 2, n){
        rd(x);
        adde(x, i), adde(i, x);
    }
    rep(i, 1, n) rd(a[i]);
    dfs(1, -1);
    printf("%lld\n", max(f[1], g[1]));
	return 0;
}
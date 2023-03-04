//ID: LRL52  Date: 2022.4.21
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = (1 << 21) + 55 , M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 1e9 + 7;
int n, m;
int fa[N], sz[N];

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main() {
#ifdef LRL52
	freopen("I.in", "r", stdin);
#endif
	rd(n), rd(m);
    rep(i, 1, n) fa[i] = i, sz[i] = 1;
    int op, x, y;
    long long ans = 0LL;
    rep(i, 1, m){
        rd(op), rd(x), rd(y);
        int fx = find(x), fy = find(y);
        if(op == 1){
            if(sz[fx] < sz[fy]) fa[fx] = fy, sz[fy] += sz[fx];
            else fa[fy] = fx, sz[fx] += sz[fy];
        }
        else{
            if(fx == fy) ans = (ans * 2 + 1) % MOD;
            else ans = ans * 2 % MOD;
        }
    }
    printf("%lld\n", ans);
	return 0;
}

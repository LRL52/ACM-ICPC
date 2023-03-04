//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 105, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
int f[N][N][5255], vis[N][N][5255], val[N], t[N];
int dfs(int n, int k, int dt){
    if(n == 0){
        if(dt == 0) return 0;
        else return -INF;
    }
    if(vis[n][k][dt + 2600]) return f[n][k][dt + 2600];
    vis[n][k][dt + 2600] = 1;
    int &F = f[n][k][dt + 2600];
    F = max(F, dfs(n - 1, k, dt));
    F = max(F, dfs(n - 1, k, dt - t[n]) + val[n]);
    F = max(F, dfs(n - 1, k, dt + t[n]) + val[n]);
    if(k > 0) F = max(F, dfs(n - 1, k - 1, dt - 2 * t[n]) + val[n]);
    if(k > 0) F = max(F, dfs(n - 1, k - 1, dt + 2 * t[n]) + val[n]);
    return F;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int n, K; rd(n), rd(K);
    rep(i, 1, n) rd(val[i]), rd(t[i]);
    dfs(n, K, 0);
    printf("%lld\n", f[n][K][0 + 2600]);
	return 0;
}
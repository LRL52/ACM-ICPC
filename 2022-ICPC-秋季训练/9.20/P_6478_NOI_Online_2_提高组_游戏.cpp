//ID: LRL52  Date: 2022.9.14
//这题题意怎么就这么别扭呢，明明和期望以及第一次分出胜负没有一点关系
//这题对方案“不同”的定义也很扯，它不考虑顺序的
//二项式反演 + 树形背包，挺不戳的题目
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5000 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int f[N], g[N], A[N], B[N], a[N], dp[N][N];
const int MOD = 998244353;
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x, int far){
    dp[x][0] = 1;
    if(a[x] == 0) A[x] = 1;
    else B[x] = 1;
    ee(I, x){
        int v = e[I].v;
        if(v == far) continue;
        dfs(v, x);
        int sizex = A[x] + B[x] - 1, sizev = A[v] + B[v];
        for(int i = sizex + sizev; i >= 0; --i){ //Size[x] = A[x] + B[x]
            for(int k = max(1, i - sizex); k <= min(sizev, i); ++k){
                dp[x][i] += 1LL * dp[v][k] * dp[x][i - k] % MOD;
                dp[x][i] %= MOD;
            }
        }
        A[x] += A[v], B[x] += B[v];
    }
    for(int i = A[x] + B[x]; i >= 1; --i){
        int t = (a[x] ? max(A[x] - (i - 1), 0) : max(B[x] - (i - 1), 0));
        dp[x][i] += 1LL * dp[x][i - 1] * t % MOD;
        dp[x][i] %= MOD;
    }
}

int inv[N], fact[N], factinv[N];
void Prework(int n){
    fact[0] = fact[1] = inv[1] = factinv[0] = factinv[1] = 1;
    rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    rep(i, 2, n) inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
    rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m){
    if(m > n || n < 0 || m < 0) return 0;
    return 1LL * fact[n] * factinv[n - m] % MOD * factinv[m] % MOD;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int x, y, m = n >> 1;
    while(cc != '1' && cc != '0') cc = gc();
    rep(i, 1, n) a[i] = cc - '0', cc = gc();
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    dfs(1, -1);
    Prework(n);
    rep(i, 0, m) f[i] = 1LL * fact[m - i] * dp[1][i] % MOD;
    for(int k = 0; k <= m; ++k){
        for(int i = k; i <= m; ++i){
            int sign = ((i - k) & 1) ? (MOD - 1) : 1;
            g[k] += 1LL * C(i, k) * sign % MOD * f[i] % MOD;
            g[k] %= MOD;
        }
    }
    for(int k = 0; k <= m; ++k) printf("%d\n", g[k]);
	return 0;
}
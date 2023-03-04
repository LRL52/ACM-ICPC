//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
const int MOD = 1e9 + 7, MAXN = 2e6;
int n, m;
int inv[N], factinv[N], fact[N];

void init(){
    inv[1] = fact[0] = fact[1] = factinv[0] = factinv[1] = 1;
    rep(i, 2, MAXN) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    rep(i, 2, MAXN) fact[i] = fact[i - 1] * i % MOD;
    rep(i, 2, MAXN) factinv[i] = factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m){
    if(m > n) return 0;
    return fact[n] * factinv[m] % MOD * factinv[n - m] % MOD;
}

/*int F(int n, int m){
    f[0][0] = 1;
        rep(i, 1, n << 1){
            for(int j = 0; j <= m; ++j){
                f[i][j] = 0;
                if(i & 1){
                    int x = (i + 1) >> 1;
                    for(int t = 0; j - t >= 0; t += x){
                        f[i][j] += f[i - 1][j - t];
                        f[i][j] %= MOD;
                    }
                } else {
                    int x = i >> 1;
                    for(int t = 0; t <= x && j - t >= 0; ++t){
                        f[i][j] += f[i - 1][j - t];
                        f[i][j] %= MOD;
                    }
                }
            }
        }
    return f[n << 1][m];
}*/
    

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    init();
	/*rep(i, 0, 10){
        rep(j, 0, 10){
            printf("%5lld ", F(i, j));
        }
        puts("");
    }*/
    int task; rd(task);
    while(task--){
        int n, m;
        rd(n), rd(m);
        printf("%lld\n", (C(n + m, n) - C(m - 1, n) + MOD) % MOD);
    }
	return 0;
}
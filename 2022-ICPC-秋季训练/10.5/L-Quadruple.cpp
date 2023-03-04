//ID: LRL52  Date: 2022.9.30
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
using LL = long long;
const int N = 2000055, inf = 0x3f3f3f3f, MOD = 998244353;
char s[N];
int n, Q, f[3][4][N], U[N], V[N];

void calc(int f[][N], const char *t) {
    int L = strlen(t);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < L; ++j) {
            f[j][i] = f[j][i - 1];
            if (s[i] == t[j]) {
                if (j == 0) f[j][i] = (f[j][i] + 1) % MOD;
                else f[j][i] = (f[j][i] + f[j - 1][i - 1]) % MOD;
            }
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("L.in", "r", stdin);
#endif
    int X, A, B, PP;
    scanf("%d%d%s%d%d%d%d", &n, &Q, s + 1, &X, &A, &B, &PP);
    calc(f[0], "ICPC");
    calc(f[1], "CPC");
    calc(f[2], "PC");
    int *ICPC = f[0][3], *ICP = f[0][2], *IC = f[0][1], *I = f[0][0];
    int *CPC = f[1][2], *CP = f[1][1], *C = f[1][0];
    int *PC = f[2][1], *P = f[2][0];
    for (int i = 1; i <= Q; ++i) {
        X = (1LL * A * X + B) % PP; 
        U[i] = X % n + 1;
    }
    for (int i = 1; i <= Q; ++i) {
        X = (1LL * A * X + B) % PP; 
        V[i] = X % n + 1;
    }
    long long ans = 0;
    for (int i = 1; i <= Q; ++i) {
        int l = min(U[i], V[i]), r = max(U[i], V[i]);
        LL c = (C[r] - C[l - 1] + MOD) % MOD;
        LL pc = (1LL * PC[r] - PC[l - 1] + MOD - (P[l - 1] * c % MOD) + MOD) % MOD;
        LL cpc = (1LL * CPC[r] - CPC[l - 1] + MOD - (C[l-1]*pc%MOD+CP[l-1]*c%MOD)%MOD + MOD) % MOD;
        LL icpc = (1LL * ICPC[r] - ICPC[l - 1] + MOD - (I[l-1]*cpc%MOD+IC[l-1]*pc%MOD+ICP[l-1]*c%MOD)%MOD + MOD) % MOD;
        ans = (ans + icpc) % MOD;
        //printf("%lld\n", icpc);
    }
    printf("%lld\n", ans);
	return 0;
}
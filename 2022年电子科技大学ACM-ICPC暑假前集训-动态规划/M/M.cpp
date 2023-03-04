//ID: LRL52  Date: 2022.5.10
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 4555; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, MOD;
int f[N], C[N][N];

int main() {
#ifdef LRL52
	freopen("M.in", "r", stdin);
#endif
    rd(n), rd(MOD);
    C[0][0] = 1;
    rep(i, 1, n){
        C[i][0] = 1;
        rep(j, 1, n)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    f[0] = f[1] = 1;
    rep(i, 2, n){
        for(int j = 1; j <= i - 1; j += 2){
            f[i] = (f[i] + 1LL * C[i - 1][j] * f[j] % MOD * f[i - 1 - j] % MOD) % MOD;
        }
    }
    printf("%d\n", 2LL * f[n] % MOD);
	return 0;
}
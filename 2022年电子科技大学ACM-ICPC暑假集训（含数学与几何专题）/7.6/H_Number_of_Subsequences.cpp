//ID: LRL52  Date: 2022.7.6
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 200055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 1e9 + 7;
char s[N];
int n;
int f[N], g[N], h[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d%s", &n, s + 1); int cnt = 1;
    rep(i, 1, n){
        f[i] = f[i - 1], g[i] = g[i - 1], h[i] = h[i - 1];
        if(s[i] == 'a'){
            f[i] = (f[i] + cnt) % MOD;
        } else
        if(s[i] == 'b'){
            g[i] = (g[i] + f[i - 1]) % MOD;
        } else
        if(s[i] == 'c'){
            h[i] = (h[i] + g[i - 1]) % MOD;
        } else {
            f[i] = (f[i] * 3LL % MOD + cnt) % MOD;
            g[i] = (g[i] * 3LL % MOD + f[i - 1]) % MOD;
            h[i] = (h[i] * 3LL % MOD + g[i - 1]) % MOD;
            cnt = cnt * 3LL % MOD;
        }
    }
    printf("%d\n", h[n]);
	return 0;
}

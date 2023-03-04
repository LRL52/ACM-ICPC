//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 500055, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MAXN = 500000;
int Pcnt, prime[N], vm[N], sigma0[N], sigma1[N], f[N], phi[N], mu[N];

void Euler(){
    mu[1] = phi[1] = sigma0[1] = sigma1[1] = f[1] = 1;
    for(int i = 2; i <= MAXN; ++i){
        if(!vm[i]){
            prime[++Pcnt] = i; vm[i] = i;
            mu[i] = -1, phi[i] = i - 1;
            sigma0[i] = 2, sigma1[i] = 1 + i;
            f[i] = 2;
        }
        for(int j = 1; prime[j] <= MAXN / i; ++j){
            int x = i * prime[j];
            if(i % prime[j]){
                vm[x] = prime[j];
                mu[x] = -mu[i], phi[x] = phi[i] * phi[prime[j]];
                sigma0[x] = sigma0[i] * sigma0[prime[j]];
                sigma1[x] = sigma1[i] * sigma1[prime[j]];
                f[x] = f[i] * f[prime[j]];
            } else{
                vm[x] = vm[i] * prime[j];
                int y = x / vm[x];
                phi[x] = phi[i] * prime[j];
                if(x == vm[x]){
                    sigma0[x] = sigma0[i] + 1;
                    sigma1[x] = sigma1[i] + x;
                    f[x] = sigma1[x] - (prime[j] - 1) * sigma1[x / prime[j]];
                } else{
                    sigma0[x] = sigma0[y] * sigma0[vm[x]];
                    sigma1[x] = sigma1[y] * sigma1[vm[x]];
                    f[x] = f[y] * f[vm[x]];
                }
                break;
            }
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("W.in", "r", stdin);
#endif
	Euler();
    int n; rd(n);
    rep(i, 1, n) printf("%d ", phi[i]); puts("");
    rep(i, 1, n) printf("%d ", mu[i]); puts("");
    rep(i, 1, n) printf("%d ", sigma0[i]); puts("");
    rep(i, 1, n) printf("%d ", sigma1[i]); puts("");
    rep(i, 1, n) printf("%d ", f[i]); puts("");
	return 0;
}
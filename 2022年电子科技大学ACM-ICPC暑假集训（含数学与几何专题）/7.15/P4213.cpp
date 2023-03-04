//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5000055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MAXN = 5000000;
typedef long long LL;
unordered_map<int, LL> H_phi, H_mu;
int Pcnt, mu[N], sum_mu[N], phi[N], st[N], prime[N];
LL sum_phi[N];

void init(){
    mu[1] = phi[1] = 1;
    for(int i = 2; i <= MAXN; ++i){
        if(!st[i]) prime[++Pcnt] = i, phi[i] = i - 1, mu[i] = -1;
        for(int j = 1; prime[j] <= MAXN / i; ++j){
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
            mu[i * prime[j]] = -mu[i];
        }
    }
    for(int i = 1; i <= MAXN; ++i){
        sum_mu[i] = sum_mu[i - 1] + mu[i];
        sum_phi[i] = sum_phi[i - 1] + phi[i];
    }
}

LL GetPhi(LL n){
    if(n <= MAXN) return sum_phi[n];
    if(H_phi.find(n) != H_phi.end()) return H_phi[n];
    LL ret = 1LL * n * (n + 1) / 2;
    for(LL l = 2, r; l <= n; l = r + 1){ //注意，这里可能爆int
        r = min(n, n / (n / l));
        ret -= (r - l + 1) * GetPhi(n / l);
    }
    return H_phi[n] = ret;
}

LL GetMu(LL n){
    if(n <= MAXN) return sum_mu[n];
    if(H_mu.find(n) != H_mu.end()) return H_mu[n];
    LL ret = 1;
    for(LL l = 2, r; l <= n; l = r + 1){ //注意，这里可能爆int
        r = min(n, n / (n / l));
        ret -= (r - l + 1) * GetMu(n / l);
    }
    return H_mu[n] = ret;
}

signed main() {
#ifdef LRL52
	freopen("P4213_11.in", "r", stdin);
#endif
    init();
	int Task, n; rd(Task);
	while(Task--){
		rd(n);
        printf("%lld %lld\n", GetPhi(n), GetMu(n));
	}
	return 0;
}
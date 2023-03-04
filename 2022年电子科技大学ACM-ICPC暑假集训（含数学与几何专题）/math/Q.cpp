//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5000055, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const LL INF = 0x7FFFFFFFFFFFFFFF;
namespace Dujiao{
    const int MAXN = 5000000;
    unordered_map<int, LL> H_phi, H_mu;
    int Pcnt, mu[N], sum_mu[N], st[N], prime[N];
    void init(){
        mu[1] = 1;
        for(int i = 2; i <= MAXN; ++i){
            if(!st[i]) prime[++Pcnt] = i, mu[i] = -1;
            for(int j = 1; prime[j] <= MAXN / i; ++j){
                st[i * prime[j]] = 1;
                if(i % prime[j] == 0) break;
                mu[i * prime[j]] = -mu[i];
            }
        }
        for(int i = 1; i <= MAXN; ++i){
            sum_mu[i] = sum_mu[i - 1] + mu[i];
        }
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
}

LL gx(LL K, LL i){
    return K / i ? K / (K / i) : INF;
}

LL gcd(LL a, LL b){return a == 0 ? b : gcd(b % a, a);}

signed main() {
#ifdef LRL52
	freopen("Q.in", "r", stdin);
#endif
    Dujiao::init();
	int Task; rd(Task);
	while(Task--){
		LL L, R;
        rd(L), rd(R);
        LL up = R, ans = 0LL;
        for(LL l = 1, r; l <= up; l = r + 1){
            r = min(up, min(gx(R, l), gx(L - 1, l)));
            LL res = (R / l - (L - 1) / l);
            res = res * res;
            ans += res * (Dujiao::GetMu(r) - Dujiao::GetMu(l - 1));
        }
        ans -= L == 1;
        LL tot = (R - L + 1) * (R - L + 1) - (R - L + 1);
        LL d = gcd(ans, tot);
        //printf("ans = %lld\n", ans);
        printf("%lld/%lld\n", ans / d, tot / d);
	}
	return 0;
}
//ID: LRL52  Date: 2022.7.11
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 50055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int Pcnt, prime[N], mu[N], sum[N], st[N];

int f(int a, int b, int k){
    a /= k, b /= k;
    int ret = 0, up = min(a, b);
    for(int l = 1, r; l <= up; l = r + 1){
        r = min(up, min(a / (a / l), b / (b / l)));
        ret += (sum[r] - sum[l - 1]) * (a / l) * (b / l);
    }
    return ret;
} 

signed main() {
#ifdef LRL52
	freopen("acwing2702.in", "r", stdin);
#endif
    mu[1] = 1;
    rep(i, 2, 50000){
        if(!st[i]) prime[++Pcnt] = i, mu[i] = -1;
        for(int j = 1; j <= Pcnt && i <= 50000 / prime[j]; ++j){
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    } 
    rep(i, 1, 50000) sum[i] = sum[i - 1] + mu[i];
	int Task; rd(Task);
	while(Task--){
		int a, b, c, d, k;
        rd(a), rd(b), rd(c), rd(d), rd(k);
        printf("%lld\n", f(b, d, k) - f(a - 1, d, k) - f(b, c - 1, k) + f(a - 1, c - 1, k));
	}
	return 0;
}

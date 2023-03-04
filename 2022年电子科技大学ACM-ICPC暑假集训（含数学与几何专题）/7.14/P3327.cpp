//ID: LRL52  Date: 2022.7.14
//莫比乌斯反演题目，yxc讲得太好辣
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 50055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int sum[N], prime[N], st[N], mu[N], h[N], Pcnt;
void init(){
    mu[1] = 1; static int UP = 50000;
    for(int i = 2; i <= UP; ++i){
        if(!st[i]) prime[++Pcnt] = i, mu[i] = -1;
        for(int j = 1; prime[j] <= UP / i; ++j){
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
 
    }
    //for(int i = 1; i <= 50; ++i) printf("%d ", prime[i]);
    for(int i = 1; i <= UP; ++i) sum[i] = sum[i - 1] + mu[i];
    for(int i = 1; i <= UP; ++i){
        for(int l = 1, r; l <= i; l = r + 1){
            r = min(i, i / (i / l));
            h[i] += (r - l + 1) * (i / l);
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("P3327.in", "r", stdin);
#endif
    init();
	int Task; rd(Task);
	while(Task--){
		int n, m; rd(n), rd(m);
        long long ans = 0;
        int up = min(n, m);
        for(int l = 1, r; l <= up; l = r + 1){
            r = min(up, min(n / (n / l), m / (m / l)));
            ans += 1LL * (sum[r] - sum[l - 1]) * h[n / l] * h[m / l];
        }
        printf("%lld\n", ans);
	}
	return 0;
}
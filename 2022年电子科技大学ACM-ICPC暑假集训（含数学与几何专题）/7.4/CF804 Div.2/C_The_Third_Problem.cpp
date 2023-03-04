//ID: LRL52  Date: 2022.7.4
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 1e9 + 7;
int n;
int Pos[N], a[N];

int main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	int T; rd(T);
    while(T--){
        rd(n);
        rep(i, 1, n) rd(a[i]), Pos[a[i]] = i;
        long long ans = 1LL;
        int L = Pos[0], R = Pos[0];
        for(int i = 1; i < n; ++i){
            int x = Pos[i];
            if(x < L || x > R){
                L = min(x, L);
                R = max(x, R);
            } else {
                ans = ans * (R - L + 1 - i) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
	return 0;
}
//ID: LRL52  Date: 2022.7.12
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, K;
map<int, int> H;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(K);
        H.clear(); int x;
        int maxv = 0, pos = 0;
        rep(i, 1, n){
            rd(x);
            x = x % K;
            if(x != 0){
                int t = ++H[x];
                if(t > maxv || (t == maxv && x < pos)){
                    maxv = t;
                    pos = x;
                }
            }
        }
        if(maxv == 0){
            puts("0");
            continue;
        }
        int ans = (maxv - 1) * K;
        ans += K - pos + 1;
        printf("%lld\n", ans);
	}
	return 0;
}

//ID: LRL52  Date: 2022.7.6
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int a[N], c[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(m);
        rep(i, 1, n) rd(a[i]);
        rep(i, 1, m) rd(c[i]);
        sort(a + 1, a + n + 1);
        long long ans = 0; int p = 0;
        for(int i = n; i >= 1; --i){
            if(p < a[i]) ans += c[++p];
            else{
                //if(p < m && c[p + 1] - c[a[i]] < c[a[i]]) ans += c[++p] - c[a[i]];
                ans += c[a[i]];
            }
        }
        printf("%lld\n", ans);
	}
	return 0;
}

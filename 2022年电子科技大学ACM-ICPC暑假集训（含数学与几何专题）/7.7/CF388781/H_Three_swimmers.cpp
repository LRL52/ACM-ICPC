//ID: LRL52  Date: 2022.7.7
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
        int a, b, c, P;
        rd(P), rd(a), rd(b), rd(c);
        int ans1 = P % a ? (a - (P % a)) : 0;
        int ans2 = P % b ? (b - (P % b)) : 0;
        int ans3 = P % c ? (c - (P % c)) : 0;
        printf("%lld\n", min(ans1, min(ans2, ans3)));
	}
	return 0;
}

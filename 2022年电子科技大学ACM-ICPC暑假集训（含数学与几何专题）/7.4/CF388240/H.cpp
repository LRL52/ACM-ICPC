//ID: LRL52  Date: 2022.7.4
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = (1e5 + 55) * 2; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int a[N];

int main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
#endif
	rd(n);
    if((n & 1) == 0){
        puts("NO");
        return 0;
    }
    puts("YES");
    rep(i, 1, n){
        int x = 2 * i - 1, y = 2 * i;
        if(i & 1) a[i] = x, a[i + n] = y;
        else a[i] = y, a[i + n] = x;
    }
    rep(i, 1, 2 * n) printf("%d ", a[i]);
	return 0;
}
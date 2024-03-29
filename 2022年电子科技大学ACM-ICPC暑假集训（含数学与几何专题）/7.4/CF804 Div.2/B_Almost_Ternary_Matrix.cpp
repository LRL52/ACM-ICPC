//ID: LRL52  Date: 2022.7.4
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

int main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	int T; rd(T);
    while(T--){
        int n, m;
        rd(n), rd(m);
        rep(i, 1, n){
            int sign = 0;
            if((i % 4) == 1 || (i % 4) == 0) sign = 1;
            rep(j, 1, m / 2){
                if(sign) printf("1 0 ");
                else printf("0 1 ");
                sign ^= 1;
            }
            putchar('\n');
        }
    }
	return 0;
}
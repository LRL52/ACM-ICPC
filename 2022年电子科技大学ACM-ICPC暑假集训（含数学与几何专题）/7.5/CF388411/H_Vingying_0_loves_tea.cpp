//ID: LRL52  Date: 2022.7.5
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
int n, K, s1, s2;
int a[N];

int main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
#endif
	rd(n), rd(K), rd(s1), rd(s2);
    int rev = 0;
    if(s1 < s2){
        swap(s1, s2);
        rev = 1;
    }
    int pair = min(s1, s2);
    s1 -= pair;
    if(pair == 0){
        if(s1 > K){
            puts("NO");
            return 0;
        }
    } else {
        //int flag = 0;
        if(s1) ++pair, --s1; //flag = 1;
        int d = s1 / pair, r = s1 % pair;
        if(1 + d + (r > 0) > K){
            puts("NO");
            return 0;
        }
        int p = 0;
        rep(i, 1, pair){
            a[++p] = 0;
            rep(j, 1, d) a[++p] = 0;
            if(r) a[++p] = 0, --r;
            a[++p] = 1;
        }
    }
    rep(i, 1, n)
        if((a[i] == 0 && rev == 0) || (a[i] == 1 && rev == 1)) putchar('G');
        else putchar('B');
	return 0;
}

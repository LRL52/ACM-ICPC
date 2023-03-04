//ID: LRL52  Date: 2022.7.8
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int a[N], use[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n) use[i] = 0;
        puts("2");
        /*for(int i = 1, val = 1; i <= n && val <= n; ++i, val <<= 1){
            printf("%d ", val);
            use[val] = 1;
        }
        rep(i, 1, n)
            if(!use[i])
                printf("%d ", i);*/
        for(int i = 1; i <= n; ++i){
            if(use[i]) continue;
            for(int j = i; j <= n; j <<= 1){
                use[j] = 1;
                printf("%d ", j);
            }
        }
        putchar('\n'); 
	}
	return 0;
}

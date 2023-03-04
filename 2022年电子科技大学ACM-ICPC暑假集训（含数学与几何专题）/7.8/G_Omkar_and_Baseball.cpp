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
int a[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n); int OK = 1;
        rep(i, 1, n){
            rd(a[i]);
            if(a[i] != i) OK = 0;
        }
        if(OK){
            puts("0");
            continue;
        }
        int l = 0, r = 0;
        rep(i, 1 ,n){
            if(a[i] != i){
                l = i;
                break;
            }
        }
        for(int i = n; i >= 1; --i){
            if(a[i] != i){
                r = i;
                break;
            }
        }
        int ok = 1;
        rep(i, l + 1, r - 1){
            if(a[i] == i){
                ok = 0;
                break;
            }
        }
        ok ? puts("1") : puts("2");
	}
	return 0;
}

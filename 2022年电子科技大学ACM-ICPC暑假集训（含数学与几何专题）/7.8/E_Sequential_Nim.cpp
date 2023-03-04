//ID: LRL52  Date: 2022.7.8
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
int n;

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n); int x;
        int cnt1 = 0, flag = 0;
        rep(i, 1, n){
            rd(x);
            if(x == 1) cnt1++;
            else{
                flag = 1;
                rep(j, i + 1, n) rd(x);
                break;
            }
        }
        if(flag == 1) (cnt1 & 1) ? puts("Second") : puts("First");
        else (cnt1 & 1) ? puts("First") : puts("Second");
        //(cnt1 & 1) || flag == 0 ? puts("Second") : puts("First");
	}
	return 0;
}

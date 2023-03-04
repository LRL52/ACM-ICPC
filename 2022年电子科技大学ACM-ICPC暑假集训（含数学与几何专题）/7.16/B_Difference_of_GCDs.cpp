//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 +55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, L, R, Ans[N];
map<int, int> vis;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
        rd(n), rd(L), rd(R);
        int ok = 1; vis.clear();
        for(int i = n; i >= 1; --i){
            int val = R / i * i;
            /*while(vis[val] && val >= L) val -= i;
            if(val >= L){
                vis[val] = 1;
                Ans[i] = val;
            } else{
                ok = 0;
                break;
            }*/
            if(val >= L && val <= R) Ans[i] = val;
            else{
                ok = 0;
                break;
            }
        }
        if(ok){
            puts("YES");
            rep(i, 1, n) printf("%d ", Ans[i]);
            puts("");
        } else{
            puts("NO");
        }
	}
	return 0;
}
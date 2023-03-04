//ID: LRL52  Date: 2022.7.17
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
set<int> s;
int n, K, Ans[N], a[N], Size[N];
int fa[N];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(K);
    rep(i, 1, n) rd(a[i]), fa[i] = i, Size[i] = 1;
    rep(i, 1, n){
        set<int>::iterator it = s.lower_bound(a[i]);
        if(it == s.end()){
            if(K > 1) s.insert(a[i]);
            else Ans[a[i]] = i;
        } else{
            int x = *it; s.erase(it);
            fa[x] = a[i];
            Size[a[i]] += Size[x];
            if(Size[a[i]] >= K) Ans[a[i]] = i;
            else s.insert(a[i]);
        }
    }
    rep(i, 1, n){
        int ans = Ans[find(i)];
        ans ? printf("%d\n", ans) : puts("-1");
    }
	return 0;
}
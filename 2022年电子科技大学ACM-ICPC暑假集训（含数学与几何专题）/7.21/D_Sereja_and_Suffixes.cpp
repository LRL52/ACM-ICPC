//ID: LRL52  Date: 2022.7.21
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 100000 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, Ans[N], vis[N], a[N];
struct Node{
    int l, id;
    inline bool operator<(const Node&t)const{
        return l < t.l;
    }
}qs[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m);
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, m){
        rd(qs[i].l);
        qs[i].id = i;
    }
    sort(qs + 1, qs + m + 1);
    int ans = 0, p = n + 1;
    for(int i = m; i >= 1; --i){
        int l = qs[i].l;
        while(p > 1 && p > l){
            int val = a[--p];
            if(!vis[val]){
                vis[val] = 1;
                ++ans;
            }
        }
        Ans[qs[i].id] = ans;
    }
    rep(i, 1, m) printf("%d\n", Ans[i]);
	return 0;
}
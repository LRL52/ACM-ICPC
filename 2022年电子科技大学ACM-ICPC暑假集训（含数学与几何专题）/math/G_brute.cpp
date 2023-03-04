//ID: LRL52  Date: 2022.7.18
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n;
struct Node{
    int x, y;
    Node operator+(const Node&t)const{
        return (Node){x + t.x, y + t.y};
    }
    Node operator-(const Node&t)const{
        return (Node){x - t.x, y - t.y};
    }
    int operator^(const Node&t)const{
        return x * t.y - y * t.x;
    }
    int operator*(const Node&t)const{
        return x * t.x + y * t.y;
    }
}a[N], b[N], O;


signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
    freopen("G_std.out", "w", stdout);
#endif
	rd(n); long long ans = 0;
    rep(i, 1, n) rd(a[i].x), rd(a[i].y);
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            for(int k = j + 1; k <= n; ++k){
                Node u = a[i], v = a[j], w = a[k];
                int ok = 1;
                ok &= (v-u)*(w-u) > 0;
                ok &= (u-v)*(w-v) > 0;
                ok &= (u-w)*(v-w) > 0;
                ans += ok;
                //if(ok == 1) printf("%d %d %d\n", i, j, k);
            }
        }
    }
    printf("%lld\n", ans);
	return 0;
}
//ID: LRL52  Date: 2022.7.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, m;
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
}a[N];

inline int Nxt(int i){return i == n ? 1 : i + 1;}

pair<int, int> winding(const Node&p){
    int ret = 0;
    for(int i = 1; i <= n; ++i){
        Node u = a[i], v = a[Nxt(i)];
        if(((p-u) ^ (p-v)) == 0 && ((p-u) * (p-v)) <= 0) return make_pair(1, 0);
        if(abs(u.y - v.y) == 0) continue;
        if(u.y < v.y && ((p-u) ^ (v-u)) >= 0) continue;
        if(u.y > v.y && ((p-u) ^ (v-u)) <= 0) continue;
        if(u.y < p.y && v.y >= p.y) ++ret;
        if(u.y >= p.y && v.y < p.y) --ret;
    }
    return make_pair(0, ret);
}

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n){
        rd(a[i].x), rd(a[i].y);
    }
    rd(m); int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        pair<int, int> ans = winding((Node){x, y});
        ans.first == 0 ? printf("%lld\n", ans.second) : puts("EDGE");
    }
	return 0;
}
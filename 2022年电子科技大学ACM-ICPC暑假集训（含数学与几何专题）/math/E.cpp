//ID: LRL52  Date: 2022.7.18
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
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
    bool operator==(const Node&t)const{
        return x == t.x && y == t.y;
    }
}a[N];

int is_on(const Node&p, const Node&a, const Node&b){
    if(p == a || p == b) return 1;
    return ((p-a)^(p-b)) == 0 && (p-a)*(p-b) < 0;
}

signed main() {
#ifdef LRL52
	freopen("E.in", "r", stdin);
#endif
	rd(a[1].x), rd(a[1].y);
    rd(a[2].x), rd(a[2].y);
    rd(a[3].x), rd(a[3].y);
    if(a[2].x < a[1].x || (a[2].x == a[1].x && a[2].y < a[1].y)) swap(a[1], a[2]);
    if(a[3].x < a[1].x || (a[3].x == a[1].x && a[3].y < a[1].y)) swap(a[1], a[3]);
    if(((a[2] - a[1])^(a[3] - a[1])) < 0) swap(a[2], a[3]);
    int qs, x, y; rd(qs);
    while(qs--){
        rd(x), rd(y);
        Node p = (Node){x, y};
        int ok = 0;
        ok |= is_on(p, a[1], a[2]);
        ok |= is_on(p, a[2], a[3]);
        ok |= is_on(p, a[3], a[1]);
        ok |= ((a[2]-a[1])^(p-a[1])) > 0 &&
              ((a[3]-a[2])^(p-a[2])) > 0 &&
              ((a[1]-a[3])^(p-a[3])) > 0;
        ok ? puts("YES") : puts("NO");
    }
	return 0;
}
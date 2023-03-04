//ID: LRL52  Date: 2022.8.27
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
int n;
struct Node{
    int x, y;
    Node operator-(const Node&t)const{
        return {x - t.x, y - t.y};
    }
}a[N];

int cross(const Node&t1, const Node&t2){
    return t1.x * t2.y - t1.y * t2.x;
}

int Nxt(int i){return i == n ? 1 : i + 1;}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	n = 4;
    rep(i, 1, n) rd(a[i].x), rd(a[i].y);
    int ok = 1;
    for(int i = 1; i <= 4; ++i){
        int j = Nxt(i), k = Nxt(j);
        if(cross(a[j] - a[i], a[k] - a[j]) > 0) continue;
        ok = 0;
        break;
    }
    ok ? puts("Yes") : puts("No");
	return 0;
}
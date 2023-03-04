//ID: LRL52  Date: 2022.7.17
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, X, Y, Z;
vector<int> Ans;
struct Node{
    int a, b, id;
}a[N], b[N];

struct cmp1{
    inline bool operator()(const Node &t1, const Node&t2)const{
        if(t1.a != t2.a) return t1.a > t2.a;
        return t1.id < t2.id;
    }
};

struct cmp2{
    inline bool operator()(const Node &t1, const Node&t2)const{
        if(t1.b != t2.b) return t1.b > t2.b;
        return t1.id < t2.id;
    }
};

struct cmp3{
    inline bool operator()(const Node &t1, const Node&t2)const{
        if(t1.a + t1.b != t2.a + t2.b) return t1.a + t1.b > t2.a + t2.b;
        return t1.id < t2.id;
    }
};

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(X), rd(Y), rd(Z);
    rep(i, 1, n) rd(a[i].a), a[i].id = i;
    rep(i, 1, n) rd(a[i].b);
    sort(a + 1, a + n + 1, cmp1());
    sort(a + X + 1, a + n + 1, cmp2());
    sort(a + X + Y + 1, a + n + 1, cmp3());
    rep(i, 1, X + Y + Z) Ans.push_back(a[i].id);
    sort(Ans.begin(), Ans.end());
    for(int i = 0; i < Ans.size(); ++i)
        printf("%d\n", Ans[i]);
	return 0;
}
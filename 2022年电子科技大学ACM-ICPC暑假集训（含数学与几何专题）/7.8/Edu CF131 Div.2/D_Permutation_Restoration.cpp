//ID: LRL52  Date: 2022.7.8
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <assert.h>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, b[N], Ans[N];
struct Node{
    int l, r, id;
    inline bool operator<(const Node&t)const{
        if(r != t.r) return r < t.r;
        return l < t.l;
    }
}a[N];
multiset<Node> s;
struct cmp{
    inline bool operator()(const Node&t1, const Node&t2)const{
        if(t1.l != t2.l) return t1.l < t2.l;
        return t1.r < t2.r;
    }
};

int main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n){
            rd(b[i]);
            a[i].l = (i + 1) % (b[i] + 1) ? (i + 1) / (b[i] + 1) + 1 : (i + 1) / (b[i] + 1);
            a[i].r = b[i] == 0 ? n : i / b[i];
            a[i].id = i;
        }
        sort(a + 1, a + n + 1, cmp());
        //rep(i, 1, n) Ans[a[i].id] = i;
        int p = 0;
        rep(i, 1, n){
            while(p < n && a[p + 1].l <= i) s.insert(a[++p]);
            multiset<Node>::iterator it = s.begin();
            Ans[it->id] = i;
            assert(it->r >= i);
            s.erase(it);
        }
        rep(i, 1, n) printf("%d ", Ans[i]);
        putchar('\n');
	}
	return 0;
}

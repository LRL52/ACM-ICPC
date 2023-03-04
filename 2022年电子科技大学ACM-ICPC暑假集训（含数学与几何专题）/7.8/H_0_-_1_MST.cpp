//ID: LRL52  Date: 2022.7.8
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int inf = 0x3f3f3f3f;
int n, m;
int head[N];
struct Edge{
    int v, nxt;
}e[M << 1];
struct Node{
    int v, viscnt;
    inline bool operator<(const Node&t)const{
        if(viscnt != t.viscnt) return viscnt < t.viscnt;
        return v < t.v;
    }
}tr[N << 2];
//multiset<Node> s;

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls (rt << 1)
#define rs (rt << 1 | 1)
void buildtree(int l, int r, int rt){
    if(l == r){
        tr[rt] = (Node){l, 0};
        return;
    }
    int mid = (l + r) >> 1;
    buildtree(lson);
    buildtree(rson);
    tr[rt] = min(tr[ls], tr[rs]);
}

void update(int x, int k, int l, int r, int rt){
    if(l == r){
        tr[rt].viscnt += k;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) update(x, k, lson);
    if(x >  mid) update(x, k, rson);
    tr[rt] = min(tr[ls], tr[rs]);
}


int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m); int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    int ans = 0;
    buildtree(1, n, 1);
    //rep(i, 1, n) s.insert((Node){i, 0});
    rep(i, 1, n){
        int x = tr[1].v, cnt = tr[1].viscnt;
        if(i != 1 && cnt >= i - 1) ++ans;
        update(x, inf, 1, n, 1);
        ee(j, x){
            int v = e[j].v;
            update(v, 1, 1, n, 1);
        }
    }
    printf("%d\n", ans);
	return 0;
}

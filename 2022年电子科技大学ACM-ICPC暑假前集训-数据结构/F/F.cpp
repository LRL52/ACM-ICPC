//ID: LRL52  Date: 2022.4.30
//树链剖分 + 可持久化01trie
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, qs, tot, DFN;
int fa[N], a[N], _a[N], dep[N], size[N], son[N], Top[N], id[N], head[N];
int rt[N * 35], tr[N * 35][2], latest[N * 35];
struct Edge{
    int v, nxt;
}e[N << 1];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = {to, head[from]};
    head[from] = et;
}

void dfs(int x){
    size[x] = 1; int maxs = 0, tson = 0;
    ee(i, x){
        int v = e[i].v;
        if(v == fa[x]) continue;
        fa[v] = x, dep[v] = dep[x] + 1;
        dfs(v);
        size[x] += size[v];
        if(size[v] > maxs){
            maxs = size[v];
            tson = v;
        }
    }
    son[x] = tson;
}

void dfs2(int x, int topx){
    id[x] = ++DFN, _a[DFN] = a[x], Top[x] = topx;
    if(son[x]) dfs2(son[x], topx);
    else return;
    ee(i, x){
        int v = e[i].v;
        if(v == fa[x] || v == son[x]) continue;
        dfs2(v, v);
    }
}

void insert(int i, int k, int old, int now){
    if(k < 0){
        latest[now] = i;
        return;
    }
    int bit = _a[i] >> k & 1;
    tr[now][bit] = ++tot, tr[now][bit^1] = tr[old][bit^1];
    insert(i, k - 1, tr[old][bit], tr[now][bit]);
    latest[now] = max(latest[tr[now][bit]], latest[tr[now][bit^1]]);
}

int query(int x, int k, int l, int now){
    if(k < 0) return _a[latest[now]] ^ x;
    int bit = x >> k & 1;
    if(latest[tr[now][bit^1]] >= l) return query(x, k - 1, l, tr[now][bit^1]);
    else return query(x, k - 1, l, tr[now][bit]);
}

int Query(int x, int y, int z){
    int ret = 0;
    while(Top[x] != Top[y]){
        if(dep[Top[x]] < dep[Top[y]]) swap(x, y);
        ret = max(ret, query(z, 30, id[Top[x]], rt[id[x]]));
        x = fa[Top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    ret = max(ret, query(z, 30, id[x], rt[id[y]]));
    return ret;
}

int main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	rd(n), rd(qs); int x, y;
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    dfs(1);
    dfs2(1, 1);
    rep(i, 1, n) {
        rt[i] = ++tot;
        insert(i, 30, rt[i-1], rt[i]);
    }
    int op, z;
    rep(i, 1, qs){
        rd(op);
        if(op == 1){
            rd(x), rd(z);
            printf("%d\n", query(z, 30, id[x], rt[id[x] + size[x] - 1]));
        } else
        if(op == 2){
            rd(x), rd(y), rd(z);
            printf("%d\n", Query(x, y, z));
        }
    }
	return 0;
}
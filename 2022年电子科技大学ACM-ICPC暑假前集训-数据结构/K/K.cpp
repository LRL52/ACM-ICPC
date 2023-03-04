//ID: LRL52  Date: 2022.4.24
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 505, N1 = N << 2, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, is_leaf, L;
int a[N][N];
int Minval[N1][N1], Maxval[N1][N1];

void buildtree(int Rt, int l, int r, int rt){
    if(l == r){
        if(is_leaf) Maxval[Rt][rt] = Minval[Rt][rt] = a[L][l];
        else{
            Maxval[Rt][rt] = max(Maxval[Rt << 1][rt], Maxval[Rt << 1 | 1][rt]);
            Minval[Rt][rt] = min(Minval[Rt << 1][rt], Minval[Rt << 1 | 1][rt]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    buildtree(Rt, l, mid, rt << 1);
    buildtree(Rt, mid + 1, r, rt << 1 | 1);
    Maxval[Rt][rt] = max(Maxval[Rt][rt << 1], Maxval[Rt][rt << 1 | 1]);
    Minval[Rt][rt] = min(Minval[Rt][rt << 1], Minval[Rt][rt << 1 | 1]);
}

void Buildtree(int l, int r, int rt){
    if(l == r){
        is_leaf = 1, L = l;
        buildtree(rt, 1, n, 1);
        return;
    }
    int mid = (l + r) >> 1;
    Buildtree(l, mid, rt << 1);
    Buildtree(mid + 1, r, rt << 1 | 1);
    is_leaf = 0;
    buildtree(rt, 1, n, 1);
}

void update(int y, int k, int Rt, int l, int r, int rt){
    if(l == r){
        if(is_leaf) Maxval[Rt][rt] = Minval[Rt][rt] = k;
        else{
            Maxval[Rt][rt] = max(Maxval[Rt << 1][rt], Maxval[Rt << 1 | 1][rt]);
            Minval[Rt][rt] = min(Minval[Rt << 1][rt], Minval[Rt << 1 | 1][rt]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if(y <= mid) update(y, k, Rt, l, mid, rt << 1);
    else update(y, k, Rt, mid + 1, r, rt << 1 | 1);
    Maxval[Rt][rt] = max(Maxval[Rt][rt << 1], Maxval[Rt][rt << 1 | 1]);
    Minval[Rt][rt] = min(Minval[Rt][rt << 1], Minval[Rt][rt << 1 | 1]);
}

void Update(int x, int y, int k, int l, int r, int rt){
    if(l == r){
        is_leaf = 1;
        update(y, k, rt, 1, n, 1);
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) Update(x, y, k, l, mid, rt << 1);
    else Update(x, y, k, mid + 1, r, rt << 1 | 1);
    is_leaf = 0;
    update(y, k, rt, 1, n, 1);
}

pair<int, int> query(int y, int v, int Rt, int l, int r, int rt){
    if(y <= l && r <= v) return make_pair(Maxval[Rt][rt], Minval[Rt][rt]);
    int mid = (l + r) >> 1;
    if(y <= mid && v > mid){
        pair<int, int> ans1 = query(y, v, Rt, l, mid, rt << 1);
        pair<int, int> ans2 = query(y, v, Rt, mid + 1, r, rt << 1 | 1);
        return make_pair(max(ans1.first, ans2.first), min(ans1.second, ans2.second));
    } else
    if(y <= mid) return query(y, v, Rt, l, mid, rt << 1);
    else return query(y, v, Rt, mid + 1, r, rt << 1 | 1);
}

pair<int, int> Query(int x, int y, int u, int v, int l, int r, int rt){
    if(x <= l && r <= u) return query(y, v, rt, 1, n, 1);
    int mid = (l + r) >> 1;
    if(x <= mid && u > mid){
        pair<int, int> ans1 = Query(x, y, u, v, l, mid, rt << 1);
        pair<int, int> ans2 = Query(x, y, u, v, mid + 1, r, rt << 1 | 1);
        return make_pair(max(ans1.first, ans2.first), min(ans1.second, ans2.second));
    } else
    if(x <= mid) return Query(x, y, u, v, l, mid, rt << 1);
    else return Query(x, y, u, v, mid + 1, r, rt << 1 | 1);
}

int main() {
#ifdef LRL52
	freopen("K.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n)
        rep(j, 1, n)
            rd(a[i][j]);
    Buildtree(1, n, 1);
    rd(m);
    int x, y, k, u, v, op;
    rep(i, 1, m){
        rd(op);
        if(op == 1){
            rd(x), rd(y), rd(k);
            Update(x, y, k, 1, n, 1);
        } else {
            rd(x), rd(y), rd(u), rd(v);
            pair<int, int> ans = Query(x, y, u, v, 1, n, 1);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
	return 0;
}
//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, K, DFN;
int fa[N], top[N], Size[N], dep[N], son[N], id[N], sumlca[N];
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N], et;

inline void adde(int from, int to){
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x){
	Size[x] = 1; int maxs = 0, tson = 0;
	ee(i, x){
		int v = e[i].v;
		if(v == fa[x]) continue;
		fa[v] = x, dep[v] = dep[x] + 1;
		dfs(v);
		Size[x] += Size[v];
		if(Size[v] > maxs){
			maxs = Size[v];
			tson = v;
		}
	}
	if(tson) son[x] = tson;
}

void dfs2(int x, int topp){
	id[x] = ++DFN, top[x] = topp;
	if(son[x]) dfs2(son[x], topp);
	else return;
	ee(i, x){
		int v = e[i].v;
		if(v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
}

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls (rt << 1)
#define rs (rt << 1 | 1)
long long add[N << 2], sum[N << 2];
inline void updatenode(int k, int l, int r, int rt){
    add[rt] += k;
    sum[rt] += k * (r - l + 1);
}

inline void pdown(int l, int r, int rt){
	if(add[rt] == 0) return;
	int mid = (l + r ) >> 1, k = add[rt];
	updatenode(k, lson), updatenode(k, rson);
	add[rt] = 0;
}

long long query(int x, int y, int l, int r, int rt){
	if(x <= l && r <= y) return sum[rt];
	int mid = (l + r) >> 1; pdown(l, r, rt);
	if(x <= mid && y > mid) return query(x, y, lson) + query(x, y, rson);
	else if(x <= mid) return query(x, y, lson);
	else return query(x, y, rson);
}

void update(int x, int y, int k, int l, int r, int rt){
	if(x <= l && r <= y){
		updatenode(k, l, r, rt);
		return;
	}
	int mid = (l + r ) >> 1; pdown(l, r, rt);
	if(x <= mid) update(x, y, k, lson);
	if(y >  mid) update(x, y, k, rson);
	sum[rt] = sum[ls] + sum[rs];
}

int LCA(int x, int y){
    while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	return x;
}

void Update(int x, int y, int k){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		update(id[top[x]], id[x], k, 1, n, 1);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	update(id[x], id[y], k, 1, n, 1);
}

long long inv[N << 1], factinv[N << 1], fact[N << 1];
const int MOD = 1e9 + 7, MAXN = 6e5; //记着改
void init(){
    inv[1] = fact[0] = fact[1] = factinv[0] = factinv[1] = 1;
    rep(i, 2, MAXN) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    rep(i, 2, MAXN) fact[i] = fact[i - 1] * i % MOD;
    rep(i, 2, MAXN) factinv[i] = factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m){
    if(m > n) return 0;
    return fact[n] * factinv[m] % MOD * factinv[n - m] % MOD;
}

long long Ans = 0;
void dfs3(int x){
    long long cnt1 = query(id[x], id[x], 1, n, 1);
    long long cnt2 = sumlca[x];
    Ans += (C(cnt1 + cnt2, K) - C(cnt1, K) + MOD) % MOD;
    Ans %= MOD;
    ee(i, x){
        int v = e[i].v;
        if(v == fa[x]) continue;
        dfs3(v);
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    init();
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(m), rd(K); int x, y;
        rep(i, 1, n) head[i] = fa[i] = top[i] = Size[i] = dep[i] = son[i] = id[i] = sumlca[i] = 0;
        DFN = et = 0;
        rep(i, 1, n << 2) sum[i] = add[i] = 0;
        rep(i, 1, n - 1){
            rd(x), rd(y);
            adde(x, y), adde(y, x);
        }
        dfs(1);
        dfs2(1, 1);
        rep(i, 1, m){
            rd(x), rd(y);
            int lca = LCA(x, y);
            sumlca[lca]++;
            Update(x, y, 1);
            Update(lca, lca, -1);
        }
        Ans = 0;
        dfs3(1);
        printf("%lld\n", Ans);
	}
	return 0;
}
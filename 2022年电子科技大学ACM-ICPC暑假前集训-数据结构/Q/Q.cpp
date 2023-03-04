//ID: LRL52  Date: 2019.9.14
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = (x << 3) + (x << 1) + (cc ^ 48); cc = gc();} x *= f;
}
int n, m, root, DFN, ct;
int w[N], id[N], dep[N], fa[N], Size[N], top[N], _w[N], son[N], head[N];
int add[N << 2];
struct edge{
	int v, nxt;
}e[N << 1];
struct Node{
    int lc, rc, cnt;
    /*inline Node operator+(const Node&t)const{
        Node ret; ret.lc = lc, ret.rc = t.rc;
        ret.cnt = cnt + t.cnt;
        if(rc == t.lc) --ret.cnt;
        return ret;
    }*/
}sum[N << 2];
inline Node operator+(const Node&t1, const Node&t2){
    Node ret; ret.lc = t1.lc, ret.rc = t2.rc;
    ret.cnt = t1.cnt + t2.cnt;
    if(t1.rc == t2.lc) --ret.cnt;
    return ret;
}

inline void adde(int from, int to){
	e[++ct].v = to;
	e[ct].nxt = head[from];
	head[from] = ct;
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
	id[x] = ++DFN, top[x] = topp; _w[id[x]] = w[x];
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
#define ls rt << 1
#define rs rt << 1 | 1
#define pup sum[rt] = sum[ls] + sum[rs]

void buildtree(int l, int r, int rt){
    add[rt] = -1;
	if(l == r){
		sum[rt].lc = sum[rt].rc = _w[l];
        sum[rt].cnt = 1;
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(lson);
	buildtree(rson);
	pup;
}

inline void updatenode(int k, int l, int r, int rt){
    add[rt] = k;
    sum[rt].lc = sum[rt].rc = k;
    sum[rt].cnt = 1;
}

inline void pdown(int l, int r, int rt){
	if(add[rt] == -1) return;
	int mid = (l + r ) >> 1, k = add[rt];
	updatenode(k, lson), updatenode(k, rson);
	add[rt] = -1;
}

void update(int x, int y, int k, int l, int r, int rt){
	if(x <= l && r <= y){
		updatenode(k, l, r, rt);
		return;
	}
	int mid = (l + r ) >> 1; pdown(l, r, rt);
	if(x <= mid) update(x, y, k, lson);
	if(y > mid) update(x, y, k, rson);
	pup;
}

Node query(int x, int y, int l, int r, int rt){
	if(x <= l && r <= y) return sum[rt];
	int mid = (l + r) >> 1; pdown(l, r, rt);
	if(x <= mid && y > mid) return query(x, y, lson) + query(x, y, rson);
	else if(x <= mid) return query(x, y, lson);
	else return query(x, y, rson);
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

int Query(int x, int y){
	Node retx, rety; int firstx = 1, firsty = 1;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]){
            if(firsty){
                firsty = 0;
                rety = query(id[top[y]], id[y], 1, n, 1);
            } else
                rety = query(id[top[y]], id[y], 1, n, 1) + rety;
            y = fa[top[y]];
        } else {
            if(firstx){
                firstx = 0;
                retx = query(id[top[x]], id[x], 1, n, 1);
            } else
                retx = query(id[top[x]], id[x], 1, n, 1) + retx;
            x = fa[top[x]];
        }
    }
	if(dep[x] > dep[y]){
        if(firstx == 0) retx = query(id[y], id[x], 1, n, 1) + retx;
        else retx = query(id[y], id[x], 1, n, 1);
        if(firsty == 0){
            swap(rety.lc, rety.rc);
            return (rety + retx).cnt;
        }
        else return retx.cnt;
    } else {
        if(firsty == 0) rety = query(id[x], id[y], 1, n, 1) + rety;
        else rety = query(id[x], id[y], 1, n, 1);
        if(firstx == 0){
            swap(retx.lc, retx.rc);
            return (retx + rety).cnt;
        }
        else return rety.cnt;
    }
}

int main(){
    freopen("R.in", "r", stdin);
	rd(n), rd(m); root = 1;
	rep(i, 1, n) rd(w[i]); int x, y, z;
	rep(i, 1, n - 1){
		rd(x), rd(y);
		adde(x, y), adde(y, x);
	}
	fa[root] = -1;
	dfs(root);
	dfs2(root, root);
	buildtree(1, n, 1);
	rep(i, 1, m){
		while(cc != 'C' && cc != 'Q') cc = gc();
		if(cc == 'C'){
			rd(x), rd(y), rd(z);
			Update(x, y, z);
		}
		else{
			rd(x), rd(y);
			printf("%d\n", Query(x, y));
		}
	}
	return 0;
}
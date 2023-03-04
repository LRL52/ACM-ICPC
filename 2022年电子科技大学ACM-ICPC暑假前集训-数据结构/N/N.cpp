//ID: LRL52  Date: 2022.4.23
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
const int N = 5e4 + 55, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0; cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = (x << 3) + (x << 1) + (cc ^ 48); cc = gc();} x *= f;
}
const int INF = 2147483647;
int n, m, b[N];
std::vector<int> a[N << 2];
#define IT std::vector<int>::iterator

inline void insert(int i, int x){a[i].insert(lower_bound(a[i].begin(), a[i].end(), x), x);}
inline void remove(int i, int x){a[i].erase(lower_bound(a[i].begin(), a[i].end(), x));}
inline int rank(int i, int x){ return --lower_bound(a[i].begin(), a[i].end(), x) - a[i].begin() + 1;}
inline int _pre(int i, int x){
	IT it = lower_bound(a[i].begin(), a[i].end(), x);
	if(it != a[i].begin()) return *--it;
	else return -INF;
}
inline int suc(int i, int x){
	IT it = upper_bound(a[i].begin(), a[i].end(), x);
	if(it != a[i].end()) return *it;
	else return INF;
}

#define pre int mid = (l + r) >> 1 
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1

void buildtree(int l, int r, int rt){
	if(l == r){
		rd(b[l]), insert(rt, b[l]);
		return;
	} 
	pre; buildtree(lson), buildtree(rson);
	for(unsigned int i = 0; i < a[ls].size(); ++i) insert(rt, a[ls][i]);
	for(unsigned int i = 0; i < a[rs].size(); ++i) insert(rt, a[rs][i]);
}

int RK(int x, int y, int k, int l, int r, int rt){ //记着输出时 + 1，现在不用了 
	if(x <= l && r <= y){
		if(*a[rt].begin() >= k) return 0;
		else return rank(rt, k);
	} 
	pre;
	if(x <= mid && y > mid) return RK(x, y, k, lson) + RK(x, y, k, rson) + (l == 1 && r == n);
	else if(x <= mid) return RK(x, y, k, lson) + (l == 1 && r == n);
	else return RK(x, y, k, rson) + (l == 1 && r == n);
}

int kth(int x, int y, int k){
	int l = 0, r = 1e8;
	while(r - l > 5){
		pre;
		if(RK(x, y, mid, 1, n, 1) > k) r = mid - 1;
		else l = mid + 1; 
	}
	for(int i = r + 1; i >= l - 1; --i) if(RK(x, y, i, 1, n, 1) <= k) return i;
	return -1;
} 

void update(int x, int k, int l, int r, int rt){
	if(l == r){
		remove(rt, b[x]), insert(rt, k);
		return;
	}
	pre; if(x <= mid) update(x, k, lson);
	else update(x, k, rson);
	remove(rt, b[x]), insert(rt, k);
}

int Pre(int x, int y, int k, int l, int r, int rt){
	if(x <= l && r <= y) return _pre(rt, k);
	pre;
	if(x <= mid && y > mid) return std::max(Pre(x, y, k, lson), Pre(x, y, k, rson));
	else if(x <= mid) return Pre(x, y, k, lson);
	else return Pre(x, y, k, rson);
}

int Suc(int x, int y, int k, int l, int r, int rt){
	if(x <= l && r <= y) return suc(rt, k);
	pre;
	if(x <= mid && y > mid) return std::min(Suc(x, y, k, lson), Suc(x, y, k, rson));
	else if(x <= mid) return Suc(x, y, k, lson);
	else return Suc(x, y, k, rson);
}

void debug(int l, int r, int rt){
	if(l == r){
		printf("rt = %d\n", rt);
		for(IT i = a[rt].begin(); i != a[rt].end(); ++i) printf("%d ", *i);
		putchar('\n'); return; 
	}
	pre;
	printf("rt = %d\n", rt);
	for(IT i = a[rt].begin(); i != a[rt].end(); ++i) printf("%d ", *i);
	putchar('\n');
	debug(lson), debug(rson);
}

int main(){
    freopen("N.in", "r", stdin);
	rd(n), rd(m); int x, y, k, op;
	buildtree(1, n, 1);
	//debug(1, n, 1); return 0;
	rep(i, 1, m){
		rd(op);
		if(op == 1) rd(x), rd(y), rd(k), printf("%d\n", RK(x, y, k, 1, n, 1) - 1);
		else if(op == 2) rd(x), rd(y), rd(k), printf("%d\n", kth(x, y, k));
		else if(op == 3) rd(x), rd(k), update(x, k, 1, n, 1), b[x] = k;
		//else if(op == 4) rd(x), rd(y), rd(k), printf("%d\n", Pre(x, y, k, 1, n, 1));
		//else rd(x), rd(y), rd(k), printf("%d\n", Suc(x, y, k, 1, n, 1));
	}
	return 0;
}
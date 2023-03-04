//ID: LRL52  Date: 2022.4.26
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
const int N = 1e5 + 55, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
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
	int l = 0, r = 32767;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(RK(x, y, mid, 1, n, 1) > k) r = mid - 1;
        else l = mid + 1;
    }
    return r;
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

int main(){
#ifdef LRL52
    freopen("C.in", "r", stdin);
    //freopen("P2617_11.in", "r", stdin);
    //freopen("P2617.out", "w", stdout);
#endif
	rd(n), rd(m); int x, y, k, op;
	buildtree(1, n, 1);
	rep(i, 1, m){
		while(cc != 'Q' && cc != 'C') cc = gc();
		if(cc == 'Q') rd(x), rd(y), rd(k), printf("%d\n", kth(x, y, k));
		else if(cc == 'C') rd(x), rd(k), update(x, k, 1, n, 1), b[x] = k;
	}
	return 0;
}
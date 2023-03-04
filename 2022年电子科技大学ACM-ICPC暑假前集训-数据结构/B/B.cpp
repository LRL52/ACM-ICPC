//ID: LRL52  Date: 2019.11.8
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 100055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
#define int long long
const int MOD = 998244353;
int n, m;
int sum[N << 2], mul[N << 2], add[N << 2];
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls (rt << 1)
#define rs (rt << 1 | 1)
inline void updatenode1(int k, int l, int r, int rt){
	mul[rt] = 1LL * mul[rt] * k % MOD;
	add[rt] = 1LL * add[rt] * k % MOD;
	sum[rt] = 1LL * sum[rt] * k % MOD;
}

inline void updatenode2(int k, int l, int r, int rt){
	(add[rt] += k) %= MOD, (sum[rt] += 1LL * (r - l + 1) * k % MOD) %= MOD;
}

inline void pdown(int l, int r, int rt){
	int mid = (l + r) >> 1;
	if(mul[rt] != 1){
		updatenode1(mul[rt], lson);
		updatenode1(mul[rt], rson);
		mul[rt] = 1;
	}
	if(add[rt] != 0){
		updatenode2(add[rt], lson);
		updatenode2(add[rt], rson);
		add[rt] = 0;
	}
}
void buildtree(int l, int r, int rt){
	add[rt] = 0, mul[rt] = 1;
	if(l == r) return rd(sum[rt]), sum[rt] %= MOD, (void)5;
	int mid = (l + r) >> 1;
	buildtree(lson);
	buildtree(rson);
	sum[rt] = (sum[ls] + sum[rs]) % MOD;
}

void update1(int x, int y, int k, int l, int r, int rt){
	if(x <= l && r <= y) return void(updatenode1(k, l, r, rt));
	int mid = (l + r) >> 1; pdown(l, r, rt);
	if(x <= mid) update1(x, y, k, lson);
	if(y > mid ) update1(x, y, k, rson);
	sum[rt] = (sum[ls] + sum[rs]) % MOD;
}

void update2(int x, int y, int k, int l, int r, int rt){
	if(x <= l && r <= y) return void(updatenode2(k, l, r, rt));
	int mid = (l + r) >> 1; pdown(l, r, rt);
	if(x <= mid) update2(x, y, k, lson);
	if(y > mid ) update2(x, y, k, rson);
	sum[rt] = (sum[ls] + sum[rs]) % MOD;
}

int query(int x, int y, int l, int r, int rt){
	if(x <= l && r <= y) return sum[rt];
	int mid = (l + r) >> 1; pdown(l, r, rt);
	if(x <= mid && y > mid) return (query(x, y, lson) + query(x, y, rson)) % MOD;
	else if(x <= mid) return query(x, y, lson);
	else return query(x, y, rson);
}

#undef int
int main(){
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
#define int long long
	rd(n), rd(m);
	buildtree(1, n, 1);
	int op, x, y, z;
	rep(i, 1, m){
		rd(op), rd(x), rd(y);
		if(op != 3) rd(z);
		if(op == 1) update1(x, y, z % MOD, 1, n, 1);
		else if(op == 2) update2(x, y, z % MOD, 1, n, 1);
		else if(op == 3) printf("%lld\n", query(x, y, 1, n, 1));
	}
	return 0;
}
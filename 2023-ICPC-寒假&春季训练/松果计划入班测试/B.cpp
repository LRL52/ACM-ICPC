/*** 
 * @Author: LRL52
 * @Date: 2023-07-01 19:30:54
 * @LastEditTime: 2023-07-01 19:35:10
 */
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = (1e5 + 55) * 2, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
int n;
int val[N];
int Len[N << 2], cover[N << 2];
struct node{
	int x, dwn, up, k;
}a[N];
struct cmp{
	inline bool operator()(const node &t1, const node &t2)const{
		return t1.x < t2.x;
	}
};

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
void update(int x, int y, int k, int l, int r, int rt){
	if(x <= l && r <= y){
		cover[rt] += k;
		if(cover[rt] > 0) Len[rt] = val[r + 1] - val[l];
		else if(l != r) Len[rt] = Len[ls] + Len[rs];
		else Len[rt] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) update(x, y, k, lson);
	if(y > mid) update(x, y, k, rson);
	if(cover[rt] > 0) Len[rt] = val[r + 1] - val[l];
	else Len[rt] = Len[ls] + Len[rs];
}

int main(){
#ifdef LRL52
	freopen("testdata.in", "r", stdin);
#endif
	// rd(n); 
    n = 2;
    int x, y, _x, _y;
	int cnt = 0, un = 0;
	rep(i, 1, n){
        int X, Y, Z;
        rd(X), rd(Y), rd(Z);
        x = X, y = Y - Z;
        _x = X + Z, _y = Y;
		// rd(x), rd(y);
        // rd(_x), rd(_y);
		a[++cnt] = (node){x, y, _y, 1};
		a[++cnt] = (node){_x, y, _y, -1};
		val[++un] = y, val[++un] = _y;
	} 
	sort(val + 1, val + un + 1);
	un = unique(val + 1, val + un + 1) - val - 1;
	sort(a + 1, a + cnt + 1, cmp());
	rep(i, 1, cnt){
		a[i].dwn = lower_bound(val + 1, val + un + 1, a[i].dwn) - val;
		a[i].up  = lower_bound(val + 1, val + un + 1, a[i].up ) - val;
	}
	update(a[1].dwn, a[1].up - 1, a[1].k, 1, un - 1, 1);
	int lstx = a[1].x;
	long long ans = 0LL;
	rep(i, 2, cnt){
		ans += 1LL * (a[i].x - lstx) * Len[1];
		lstx = a[i].x;
		update(a[i].dwn, a[i].up - 1, a[i].k, 1, un - 1, 1);
	} 
	printf("%lld\n", ans);
	return 0;
}
//ID: LRL52  Date: 2022.8.12
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const int MOD = 1e9 + 7;
int n;
const int f[1][5] = {
	{15, 5, 1, 3, 1},
};
const int g[5][5] = {
	{3,     1, 0, 0, 0},
	{MOD-3, 0, 1, 0, 0},
	{1,     0, 0, 0, 0},
    {1,     0, 0, 1, 0},
    {1,     0, 0, 1, 1},
};
struct Mat{
	int c, r, a[5][5];
	Mat(){memset(a, 0, sizeof a); c = r = 0;}
	Mat(int x){
		c = r = x; memset(a, 0, sizeof a);
		for(int i = 0; i < x; ++i) a[i][i] = 1;
	}
	inline Mat operator*(const Mat &t)const{
	    Mat ret; ret.c = c, ret.r = t.r;
		for(int i = 0; i < c; ++i)
		    for(int j = 0; j < t.r; ++j)
			    for(int k = 0; k < r; ++k)
				    ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * t.a[k][j] % MOD) % MOD;
	    return ret;	
	}
	friend Mat operator^(Mat A, LL k){
		Mat ret(A.c);
		while(k){
			if(k & 1) ret = ret * A;
			A = A * A;
			k >>= 1;
		}
		return ret;
	}
}F, G;

LL ksm(LL a, LL k){
    LL ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

void Solve(){
	rd(n);
	/*if(n <= 3){
        if(n == 1) puts("1");
        if(n == 2) puts("5");
        if(n == 3) puts("15");
        return;
    }
	memcpy(G.a, g, sizeof g);
	G.c = G.r = 5;
	memcpy(F.a, f, sizeof f);
	F.c = 1, F.r = 5;
	G = G ^ (n - 3);
	F = F * G;
	printf("%d\n", F.a[0][0]);*/
    LL ans = 0;
    LL inv4 = ksm(4, MOD - 2), inv24 = ksm(24, MOD - 2);
    ans = inv24 * ksm(n, 4) % MOD;
    ans = (ans + inv4 * ksm(n, 3) % MOD) % MOD;
    ans = (ans + 11LL * inv24 % MOD * ksm(n, 2) % MOD) % MOD;
    ans = (ans + inv4 * n % MOD) % MOD;
    printf("%lld\n", (ans % MOD + MOD) % MOD);
}

int main(){
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	int T; rd(T);
	while(T--) Solve();
	return 0;
}

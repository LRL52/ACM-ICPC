//ID: LRL52  Date: 2022.8.2
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
#define int long long
const int MOD = 1e9 + 7;
int f[2][2][75][75], num[75];

int ksm(int a, int k){
    if(a == 0) return 0;
    int ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

int dfs(int lim, int lead, int pos, int cnt, int B, int d){
    assert(lim < 2 && lead < 2 && pos <= 64 && cnt <= 64 && cnt > -2);
    if(cnt < 0) return 0;
    int &F = f[lim][lead][pos][cnt];
    if(F != -1) return F;
    if(pos == 0) return F = (cnt == 0);
    int up = lim ? num[pos] : (B - 1);
    F = 0;
    F = (F + dfs(0 == up && lim, lead, pos - 1, cnt - (d == 0 && lead), B, d)) % MOD;
    if(0 < up) F = (F + dfs(lim, lead || up, pos - 1, cnt - (d == up), B, d)) % MOD;
    if(1 <= up - 1){
        int rg = up - 1;
        if(d > 0 && d < up){
            F = (F + dfs(0, 1, pos - 1, cnt - 1, B, d)) % MOD;
            F = (F + (rg - 1) * dfs(0, 1, pos - 1, cnt, B, d) % MOD) % MOD;
        } else{
            F = (F + rg * dfs(0, 1, pos - 1, cnt, B, d) % MOD) % MOD;
        }
    }
    assert(F >= 0);
    return F;
}

int Solve(int K, int B, int d, int Num){
    memset(f, -1, sizeof f);
    int len = 0;
    while(Num){
        num[++len] = Num % B;
        Num /= B;
    }
    int ret = 0;
    for(int cnt = 0; cnt <= 64; ++cnt){
        //memset(f, -1, sizeof f);
        int res = dfs(1, 0, len, cnt, B, d);
        ret = (ret + ksm(cnt, K) * res % MOD) % MOD;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	int Task; rd(Task);
    int K, B, d, l, r;
	while(Task--){
		rd(K), rd(B), rd(d), rd(l), rd(r);
        int ans = (Solve(K, B, d, r) - Solve(K, B, d, l - 1) + MOD) % MOD;
        printf("%lld\n", (ans % MOD + MOD) % MOD);
	}
	return 0;
}
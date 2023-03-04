//ID: LRL52  Date: 2022.5.12
//数位DP，注意前导0的处理，细节处理了好久qwq
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 998244353;
int Ans[N], f[21][2][2][N], g[21][2][2][N], num[N], pow10[N];

int dfs(int pos, int lim, int lead, int sta){
    int &ans = f[pos][lim][lead][sta], &cnt = g[pos][lim][lead][sta];
    if(ans != -1) return ans;
    if(pos == 0){
        if(sta == 0) return cnt = 1, ans = 0;
        else return ans = cnt = 0;
    }
    ans = cnt = 0;
    int up = lim ? num[pos] : 9;
    if(lead == 0){
        dfs(pos - 1, 0, 0, sta);
        cnt = (cnt + g[pos-1][0][0][sta]) % MOD;
        ans = (1LL * ans + f[pos-1][0][0][sta]) % MOD;
    }
    for(int i = 0; i <= up; ++i){
        if((sta >> i & 1) == 0) continue;
        if(i == 0 && lead == 0) continue;
        int r = (i == up && lim), s = lead || i;
        dfs(pos - 1, r, s, sta);
        cnt = (cnt + g[pos-1][r][s][sta]) % MOD;
        ans = (1LL * ans + f[pos-1][r][s][sta] 
        + 1LL * g[pos-1][r][s][sta] * pow10[pos-1] % MOD * i % MOD) % MOD;
        int sta2 = sta ^ (1 << i);
        dfs(pos -1, r, s, sta2);
        cnt = (cnt + g[pos-1][r][s][sta2]) % MOD;
        ans = (1LL * ans + f[pos-1][r][s][sta2]
        + 1LL * g[pos-1][r][s][sta2] * pow10[pos-1] % MOD * i % MOD) % MOD;
    }
    return ans;
}



void Solve(long long Num, int sign){
    memset(f, -1, sizeof f);
    int len = 0;
    while(Num){
        num[++len] = Num % 10;
        Num /= 10;
    }
    for(int i = 0; i < 1 << 10; ++i){
        dfs(len, 1, 0, i);
        int k = 0;
        for(int j = 0; j < 10; ++j)
            if(i >> j & 1) ++k;
        Ans[k] = (Ans[k] + 1LL * f[len][1][0][i] * sign + MOD) % MOD;
    }
}

int main() {
#ifdef LRL52
	freopen("S.in", "r", stdin);
#endif
    pow10[0] = 1; long long L, R;
    rep(i, 1, 20) pow10[i] = pow10[i - 1] * 10LL % MOD;
    rd(L), rd(R);
    Solve(R, 1);
    Solve(L - 1, -1);
    rep(i, 2, 10) Ans[i] = ((Ans[i] + Ans[i - 1]) % MOD + MOD) % MOD;
    rep(i, 1, 10) printf("%d ", Ans[i]);
	return 0;
}
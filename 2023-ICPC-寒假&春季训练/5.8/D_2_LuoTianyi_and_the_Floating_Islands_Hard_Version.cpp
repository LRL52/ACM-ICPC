/*** 
 * @Author: LRL52
 * @Date: 2023-05-09 10:04:18
 * @LastEditTime: 2023-05-09 10:17:51
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, K;
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N], Size[N];
i64 Ans = 1;

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

const int MOD = 1e9 + 7;
int inv[N], fact[N], factinv[N];
void Prework(int n){
    fact[0] = fact[1] = inv[1] = factinv[0] = factinv[1] = 1;
    rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    rep(i, 2, n) inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
    rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m){
    if(m > n || n < 0 || m < 0) return 0;
    return 1LL * fact[n] * factinv[n - m] % MOD * factinv[m] % MOD;
}

typedef long long LL;
LL ksm(LL a, LL k){
    LL ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

i64 Inv(i64 x) { return ksm(x % MOD, MOD - 2); }

void dfs(int x, int far) {
    Size[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (v == far) continue;
        dfs(v, x);
        Size[x] += Size[v];
        Ans += 1LL * C(Size[v], K / 2) * C(n - Size[v], K / 2) % MOD;
        Ans %= MOD;
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> K;
    Prework(n);
    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adde(x, y), adde(y, x);
    }
    if (K % 2 == 0) {
        Ans = 0;
        dfs(1, -1);
        auto d = C(n, K);
        Ans = 1LL * Ans * Inv(d) % MOD;
        Ans = (Ans + 1) % MOD;
    }
    cout << Ans << '\n';
	return 0;
}
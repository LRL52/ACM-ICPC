/*** 
 * @Author: LRL52
 * @Date: 2023-05-26 00:19:46
 * @LastEditTime: 2023-05-26 01:03:39
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, inf = 0x3f3f3f3f, MOD = 998244353;
int K, n;
int a[N], tr[N << 2], fact[N], Cnt[N];
i64 ans = 1;

#define ls (rt << 1)
#define rs (rt << 1 | 1)

void init(int l, int r, int rt, int dep) {
    if (l == r) {
        if (a[l] != -1) tr[rt] = a[l];
        else tr[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    init(l, mid, ls, dep + 1);
    init(mid + 1, r, rs, dep + 1);
    int range = 1 << dep;
    if (tr[ls] && tr[rs]) {
        int win = min(tr[ls], tr[rs]), lose = max(tr[ls], tr[rs]); 
        if (win <= range && lose > range) tr[rt] = win;
        else if (win > range || lose <= range) ans = 0;
    } else if (tr[ls] || tr[rs]) {
        tr[rt] = max(tr[ls], tr[rs]);
    }
    if (tr[rt] && tr[rt] > range) tr[rt] = 0;
}

void dfs(int l, int r, int rt, int dep) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (tr[ls] == 0 && tr[rs] == 0) ans = ans * 2LL % MOD;
    if ((tr[ls] == 0 && tr[rs] == 0) || (tr[rt] && (tr[ls] == 0 || tr[rs] == 0))) ++Cnt[dep];
    dfs(l, mid, ls, dep + 1);
    dfs(mid + 1, r, rs, dep + 1);
}

signed main()  {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> K; n = 1 << K;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) cin >> a[i], fact[i] = 1LL * fact[i - 1] * i % MOD;
    init(1, n, 1, 0);
    dfs(1, n, 1, 0);
    for (int i = 0; i <= K; ++i) ans = ans * fact[Cnt[i]] % MOD;
    cout << ans << '\n';
	return 0;
}
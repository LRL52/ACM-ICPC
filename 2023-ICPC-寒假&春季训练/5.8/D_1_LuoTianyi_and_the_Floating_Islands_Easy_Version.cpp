/*** 
 * @Author: LRL52
 * @Date: 2023-05-08 21:32:29
 * @LastEditTime: 2023-05-08 22:41:59
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
#define int long long
int n, K;
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N], Size[N];
i64 ans = 0;

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
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
    int sum = 0;
    for (int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (v == far) continue;
        dfs(v, x);
        Size[x] += Size[v];
        // if (K == 2) {
            ans += 1LL * sum * Size[v] % MOD;
            ans %= MOD;
        // }
        sum += Size[v];
    }
    if (K == 2) {
        ans += 1LL * Size[x] * (n - Size[x] + 1) % MOD;
        ans %= MOD;
    }
    if (K == 3) {
        ans += 1LL * (Size[x] - 1) * (n - Size[x]) % MOD;
        ans %= MOD;
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; 
    //cin >> Task;
    Task = 1;
	while(Task--) { 
		cin >> n >> K;
        for (int i = 1; i <= n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            adde(x, y), adde(y, x);
        }
        if (K == 1 || K == 3) {
            puts("1");
            continue;
        }
        dfs(1, -1);
        i64 d;
        if (K == 2) d = 1LL * n * (n - 1) / 2LL;
        else d = 1LL * n * (n - 1) * (n - 2) / 6LL;
        // cout << ans << '\n';
        if (K == 2) ans = (ans - n + MOD) % MOD;
        ans = 1LL * ans * Inv(d) % MOD;
        cout << ans << '\n';
	}
	return 0;
}
/*** 
 * @Author: LRL52
 * @Date: 2023-03-09 12:46:16
 * @LastEditTime: 2023-03-09 13:23:00
 */
//KMP匹配两个数组相等
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, m, MOD;
int a[N], b[N], diff_a[N], diff_b[N], nxt[N];

signed main() {
#ifdef LRL52
	freopen("nc14694.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> m >> MOD;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, m) cin >> b[i];
        rep(i, 1, n - 1) diff_a[i] = ((a[i] - a[i + 1]) % MOD + MOD) % MOD;
        rep(i, 1, m - 1) diff_b[i] = ((b[i + 1] - b[i]) % MOD + MOD) % MOD;
        --m, --n;
        for(int i = 2, j = 0; i <= m; ++i) {
            while(j > 0 && diff_b[j + 1] != diff_b[i]) j = nxt[j];
            if(diff_b[j + 1] == diff_b[i]) ++j;
            nxt[i] = j;
        }
        int ans = 0;
        for(int i = 1, j = 0; i <= n; ++i) {
            while(j > 0 && diff_b[j + 1] != diff_a[i]) j = nxt[j];
            if(diff_b[j + 1] == diff_a[i]) ++j;
            ans += j == m;
        }
        cout << ans << '\n';
	}
	return 0;
}
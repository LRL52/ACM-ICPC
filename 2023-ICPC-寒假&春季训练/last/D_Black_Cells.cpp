/*** 
 * @Author: LRL52
 * @Date: 2023-04-20 23:47:38
 * @LastEditTime: 2023-04-21 00:13:44
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, K;
int L[N], R[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> K;
        for (int i = 1; i <= n; ++i)
            cin >> L[i];
        for (int i = 1; i <= n; ++i)
            cin >> R[i];
        i64 ans = 1e16, cnt1 = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            int len = R[i] - L[i] + 1;
            i64 lastsum = sum;
            sum += len;
            if (sum >= K) {
                i64 pos = max(R[i] - (sum - K), (i64)L[i]);
                i64 res = pos + i * 2LL;
                i64 t = cnt1;
                if (lastsum + 1 > K) {   
                    auto dt = min(lastsum + 1 - K, (i64)t);
                    t -= dt;
                    res -= 2 * dt;
                }   
                res -= min(R[i] - pos, t);
                ans = min(ans, res);
            }
            cnt1 += len == 1;
        }
        if (ans == 1e16) cout << -1 << '\n';
        else cout << ans << '\n';
	}
	return 0;
}
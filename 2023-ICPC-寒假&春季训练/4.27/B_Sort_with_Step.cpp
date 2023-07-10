/*** 
 * @Author: LRL52
 * @Date: 2023-04-27 22:47:39
 * @LastEditTime: 2023-04-27 22:53:19
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, K;
int a[N], vis[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> K;
        for (int i = 1; i <= n; ++i) cin >> a[i], vis[i] = 0;
        int cnt = 0;
        for (int st = 0; st < K; ++st) {
            for (int i = 1 + st; i <= n; i += K) vis[i] = 1;
            for (int i = 1 + st; i <= n; i += K) {
                auto x = a[i];
                vis[x]--;
            }
            for (int i = 1 + st; i <= n; i += K)
                if (vis[i] == 1)
                    ++cnt;
            for (int i = 1 + st; i <= n; i += K)
                vis[i] = vis[a[i]] = 0;
        }
        if (cnt == 0) puts("0");
        else if (cnt <= 2) puts("1");
        else puts("-1");
	}
	return 0;
}
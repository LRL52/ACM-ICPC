/*** 
 * @Author: LRL52
 * @Date: 2023-06-03 22:43:08
 * @LastEditTime: 2023-06-03 22:53:08
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		int n, K;
        cin >> n >> K;
        int ans = 0, i, j;
        for (i = 1, j = n; i <= j; i += K, j -= K) 
            if (i != j) ans += 2;
            else ans++;
        if (i < j + K) ++ans;
        cout << ans << '\n';
	}
	return 0;
}
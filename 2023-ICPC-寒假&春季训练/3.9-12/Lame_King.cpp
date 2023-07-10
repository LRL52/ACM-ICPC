/*** 
 * @Author: LRL52
 * @Date: 2023-03-12 22:40:24
 * @LastEditTime: 2023-03-12 22:47:34
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		int x, y;
        cin >> x >> y;
        x = abs(x), y = abs(y);
        int d = abs(y - x);
        int ans = min(x, y) * 2;
        for(int i = 1; i <= d; ++i)
            if(i == 1) ans++;
            else ans += 2;
        cout << ans << '\n';
	}
	return 0;
}
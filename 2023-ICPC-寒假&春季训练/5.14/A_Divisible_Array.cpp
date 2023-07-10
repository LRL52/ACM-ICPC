/*** 
 * @Author: LRL52
 * @Date: 2023-05-14 22:36:58
 * @LastEditTime: 2023-05-14 22:36:58
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
		int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cout << i * 2 << ' ';
        cout << '\n';
	}
	return 0;
}
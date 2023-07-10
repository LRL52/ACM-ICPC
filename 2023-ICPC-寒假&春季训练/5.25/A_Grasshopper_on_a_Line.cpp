/*** 
 * @Author: LRL52
 * @Date: 2023-05-25 22:37:29
 * @LastEditTime: 2023-05-25 22:37:30
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
		int x, k;
        cin >> x >> k;
        if (x % k == 0) {
            printf("%d\n%d %d\n", 2, x - 1, 1);
        } else {
            printf("%d\n%d\n", 1, x);
        }
	}
	return 0;
}
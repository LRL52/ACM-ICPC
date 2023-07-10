/*** 
 * @Author: LRL52
 * @Date: 2023-05-05 22:56:18
 * @LastEditTime: 2023-05-05 23:04:15
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
int n, m;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> m;
        if (n == 1) {
            puts("YES");
            continue;
        }
        int d = n;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }
        if (d > m) puts("YES");
        else puts("NO");
	}
	return 0;
}
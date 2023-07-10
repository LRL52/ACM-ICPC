/*** 
 * @Author: LRL52
 * @Date: 2023-04-27 22:42:02
 * @LastEditTime: 2023-04-27 22:43:57
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
		int n, K;
        cin >> n >> K;
        auto r1 = -1, r2 = -1;
        for (int i = 0; i <= n; ++i) {
            auto cnt1 = i * (i - 1) / 2;
            auto cnt2 = (n - i) * (n - i - 1) / 2;
            if (cnt1 + cnt2 == K) {
                r1 = i, r2 = n - i;
                break;
            }
        }
        if (r1 == -1) puts("NO");
        else {
            puts("YES");
            for (int i = 1; i <= r1; ++i) printf("1 ");
            for (int i = 1; i <= r2; ++i) printf("-1 ");
            puts("");
        }
	}
	return 0;
}
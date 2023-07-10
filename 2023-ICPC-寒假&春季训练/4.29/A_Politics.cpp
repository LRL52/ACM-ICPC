/*** 
 * @Author: LRL52
 * @Date: 2023-04-29 22:44:42
 * @LastEditTime: 2023-04-29 22:47:10
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
char s[N][N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
        int n, K;
		cin >> n >> K;
        for (int i = 1; i <= n; ++i) {
            cin >> (s[i] + 1);
        }
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            int ok = 1;
            for (int j = 1; j <= K; ++j) {
                if (s[i][j] != s[1][j]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
        cout << ans << '\n';
	}
	return 0;
}
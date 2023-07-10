/*** 
 * @Author: LRL52
 * @Date: 2023-05-25 22:42:41
 * @LastEditTime: 2023-05-25 22:58:19
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        // map<int, int> H;
        cin >> (s + 1);
        // H[0] = 1;
        // int ans = 1, last = 0;
        // for (int i = 1; i <= n; ++i) {
        //     int now;
        //     if (s[i] == '<') {
        //         now = last + 1;
        //     } else {
        //         now = last - 1;
        //     }
        //     if (H.find(now) == H.end()) {
        //         ++ans;
        //         H[now] = 1;
        //     }
        //     last = now;
        // }
        // cout << ans << '\n';
        int ans = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            while (j < n && s[j + 1] == s[i]) ++j;
            ans = max(ans, j - i + 1);
        }
        cout << ans + 1 << '\n';
	}
	return 0;
}
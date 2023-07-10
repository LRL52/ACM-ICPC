/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:44:05
 * @LastEditTime: 2023-05-12 23:10:02
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 3e5 + 55, inf = 0x3f3f3f3f;
int n;
int a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            ++ans;
            j = i;
            while (j < n && a[j + 1] == a[j]) ++j;
            if (j == n) break;
            int sign = (a[j + 1] - a[j]) > 0 ? 1 : -1;
            while (j + 1 < n && (a[j + 2] - a[j + 1]) * sign >= 0) ++j;
        }
        cout << ans << '\n';
	}
	return 0;
}
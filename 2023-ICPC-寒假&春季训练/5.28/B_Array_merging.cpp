/*** 
 * @Author: LRL52
 * @Date: 2023-05-28 22:42:12
 * @LastEditTime: 2023-05-28 22:46:07
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 4e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, a[N], b[N], L1[N], L2[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= 2 * n; ++i) L1[i] = L2[i] = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i; int x = a[i];
            while (j < n && a[j + 1] == a[i]) ++j;
            int len = j - i + 1;
            L1[x] = max(L1[x], len);
        }
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i; int x = b[i];
            while (j < n && b[j + 1] == b[i]) ++j;
            int len = j - i + 1;
            L2[x] = max(L2[x], len);
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n; ++i) ans = max(ans, L1[i] + L2[i]);
        cout << ans << '\n';
	}
	return 0;
}
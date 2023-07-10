/*** 
 * @Author: LRL52
 * @Date: 2023-04-20 22:52:14
 * @LastEditTime: 2023-04-20 22:54:00
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, a[N], b[N];

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
        int l = n, r = 1;
        for (int i = 1; i <= n; ++i)
            if (a[i] != b[i])
                l = min(l, i), r = max(r, i);
        while (l > 1 && b[l - 1] <= b[l]) --l;
        while (r < n && b[r + 1] >= b[r]) ++r;
        printf("%d %d\n", l, r);
	}
	return 0;
}
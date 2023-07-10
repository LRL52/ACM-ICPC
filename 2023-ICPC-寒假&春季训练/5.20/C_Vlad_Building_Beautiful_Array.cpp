/*** 
 * @Author: LRL52
 * @Date: 2023-05-19 22:55:59
 * @LastEditTime: 2023-05-19 22:57:42
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
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
        int even_all = 1;
        for (int i = 1; i <= n; ++i) cin >> a[i], even_all &= ((a[i] & 1) == 0);
        sort(a + 1, a + n + 1);
        if (even_all || (a[1] & 1)) puts("YES");
        else puts("NO");
	}
	return 0;
}
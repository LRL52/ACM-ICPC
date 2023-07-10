/*** 
 * @Author: LRL52
 * @Date: 2023-05-25 23:19:00
 * @LastEditTime: 2023-05-25 23:25:32
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, a[N], Ans[N];
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> (s + 1);
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '(') a[i] = a[i - 1] + 1;
            else a[i] = a[i - 1] - 1;
        }
        if (a[n] != 0) {
            puts("-1");
            continue;
        }
        // set<int> ans;
        int f1 = 0, f2 = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] >= 0 && a[i] >= 0) {
                if (!f1) f1 = ++ans;
                Ans[i] = f1;
            }
            else if (a[i - 1] <= 0 && a[i] <= 0) {
                if (!f2) f2 = ++ans;
                Ans[i] = f2;
            }
        }
        printf("%d\n", ans);
        for (int i = 1; i <= n; ++i) printf("%d ", Ans[i]);
        puts("");
	}
	return 0;
}
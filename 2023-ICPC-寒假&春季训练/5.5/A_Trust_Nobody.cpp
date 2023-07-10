/*** 
 * @Author: LRL52
 * @Date: 2023-05-05 22:41:40
 * @LastEditTime: 2023-05-05 22:43:54
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
int a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        int n;
		cin >> n;
        rep(i, 1, n) cin >> a[i];
        int ok = -1;
        for (int ans = 0; ans <= n; ++ans) {
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] > ans) 
                    ++cnt;
            }
            if (cnt == ans) {
                ok = ans;
                break;
            }
        }
        cout << ok << endl;
	}
	return 0;
}
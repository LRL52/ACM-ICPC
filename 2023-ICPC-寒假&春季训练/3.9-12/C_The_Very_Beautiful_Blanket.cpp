/*** 
 * @Author: LRL52
 * @Date: 2023-03-09 22:17:14
 * @LastEditTime: 2023-03-09 23:23:24
 */
//考试题读挂了，难受
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
        int n, m;
        cin >> n >> m;
        cout << n * m << '\n';
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cout << (i << 8) + j << " \n"[j == m]; 
	}
	return 0;
}
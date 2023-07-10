/*** 
 * @Author: LRL52
 * @Date: 2023-03-09 17:46:53
 * @LastEditTime: 2023-03-09 17:47:32
 */
/*** 
 * @Author: LRL52
 * @Date: 2023-03-09 17:40:10
 * @LastEditTime: 2023-03-09 17:46:53
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
		int n, cnt1 = 0, cnt2 = 0;;
        cin >> n;
        rep(i, 1, n) {
            int x;
            cin >> x;
            cnt1 += x > 0;
            cnt2 += x < 0;
        }
        int sum = 0;
        rep(i, 1, n) {
            if(cnt1 > 0) sum++, cnt1--;
            else --sum;
            cout << sum << " \n"[i == n];
        }
        sum = 0;
        rep(i, 1, n) {
            if(cnt2 > 0) {
                ++i, --cnt2;
                cout << sum + 1 << " " << sum << " \n"[i == n];
            } else {
                cout << ++sum << " \n"[i == n];
            }
        }
	}
	return 0;
}
/*** 
 * @Author: LRL52
 * @Date: 2023-05-08 20:07:33
 * @LastEditTime: 2023-05-08 20:09:31
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> (s + 1);
        int n = strlen(s + 1);
        if (n == 1) {
            puts("-1");
            continue;
        }
        int ok = 1;
        for (int i = 1, j = n - 1; i <= j; ++i, --j)
            if (s[i] != s[j]) {
                ok = 0;
                break;
            }
        printf("%d\n", ok == 0 ? n - 1 : -1);
	}
	return 0;
}
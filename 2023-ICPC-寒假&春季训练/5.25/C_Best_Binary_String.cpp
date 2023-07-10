/*** 
 * @Author: LRL52
 * @Date: 2023-05-25 23:02:31
 * @LastEditTime: 2023-05-25 23:03:28
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 3e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
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
        char last = '0';
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '?') s[i] = last;
            last = s[i];
        }
        cout << (s + 1) << '\n';
	}
	return 0;
}
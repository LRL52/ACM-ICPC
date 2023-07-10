/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:44:05
 * @LastEditTime: 2023-05-12 22:37:28
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
        set<char> S;
        for (int i = 1, j = n; i < j; ++i, --j) {
            S.insert(s[i]);
        }
        puts(S.size() > 1 ? "YES" : "NO");
	}
	return 0;
}
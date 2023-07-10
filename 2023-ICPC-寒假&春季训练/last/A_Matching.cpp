/*** 
 * @Author: LRL52
 * @Date: 2023-04-20 22:37:19
 * @LastEditTime: 2023-04-20 22:44:44
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
char s[N];
int n, ans;

// void dfs(int x) {
//     if (x == n + 1) {
        
// }

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> (s + 1);
        n = strlen(s + 1);
        // if (n == 1 && s[1] == '0') {
        //     puts("0");
        //     continue;
        // }
        // if (n == 1 && s[1] == '?') {
        //     puts("10");
        //     continue;
        // }
        ans = s[1] != '0';
        if (s[1] == '?') ans = 9;
        for (int i = 2; i <= n; ++i) {
            if (s[i] == '?')
                ans *= 10;
        }
        cout << ans << '\n';
	}
	return 0;
}
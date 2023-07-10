/*** 
 * @Author: LRL52
 * @Date: 2023-06-17 10:54:18
 * @LastEditTime: 2023-06-17 10:59:27
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 5e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
char s[N];
int f[N][N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> (s + 1);
    int n = strlen(s + 1);
    i64 ans = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
            else if (s[i] > s[j]) f[i][j] = 1;
            else f[i][j] = 0;
            ans += f[i][j];
        }
    }
    cout << ans << '\n';
	return 0;
}
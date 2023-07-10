/*** 
 * @Author: LRL52
 * @Date: 2023-03-12 23:47:02
 * @LastEditTime: 2023-03-13 00:32:53
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 5e5 + 55, inf = 0x3f3f3f3f;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int minv = 0, maxv = 0;
    for(int tt = 1; tt <= n; ++tt) {
        cin >> (s + 1);
        int one = m / 2, two = m / 4;
        for(int i = 1, j; i <= m; i = j + 1) {
            j = i;
            if(s[i] == '0') continue;
            while(j < m && s[j + 1] == '1') ++j;
            int len = j - i + 1;
            if(len == 1) minv++;
            else {
                int res = min(two, len / 2);
                two -= res;
                minv += res + (len - res * 2);
            }
        }
        one = m / 2, two = m / 4;
        for(int i = 1, j; i <= m; i = j + 1) {
            j = i;
            int cnt = s[i] == '1';
            while(j < m && (s[j + 1] == '0' || s[j + 1] != s[j])) {
                ++j;
                cnt += s[j] == '1';
            }
            int len = j - i + 1;
            if(len == 1) continue;
            maxv += cnt;
            int res = min(two, len / 2);
            two -= res;
            one -= len - res * 2;
        }
        assert(one >= 0 && two >= 0);
        maxv += two + one;
    }
    cout << minv << " " << maxv << '\n';
	return 0;
}
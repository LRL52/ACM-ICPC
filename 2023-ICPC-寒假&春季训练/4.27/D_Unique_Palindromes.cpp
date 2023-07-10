/*** 
 * @Author: LRL52
 * @Date: 2023-04-28 22:56:36
 * @LastEditTime: 2023-04-28 23:18:12
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, K;
int X[N], C[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> K;
        int p = 0;
        auto getChar = [&p]() {
            static const char *str = "abc";
            auto ret = str[p];
            p = (p + 1) % 3;
            return ret;
        };
        string ans; int ok = 1;
        char c = 'd';
        X[0] = C[0] = 3;
        ans.push_back(getChar());
        ans.push_back(getChar());
        ans.push_back(getChar());
        for (int i = 1; i <= K; ++i) cin >> X[i];
        for (int i = 1; i <= K; ++i) cin >> C[i];
        for (int i = 1; i <= K; ++i) {
            // cin >> X[i] >> C[i];
            // if (!ok) continue;
            int cnt = C[i] - C[i - 1];
            int padLen = X[i] - X[i - 1] - cnt;
            if (padLen < 0) {
                ok = 0;
                break;
            }
            for (int j = 1; j <= padLen; ++j) {
                ans.push_back(getChar());
            }
            for (int j = 1; j <= cnt; ++j) {
                ans.push_back(c);
            }
            if (cnt > 0) c++;
        }
        for (int i = X[K] + 1; i <= n; ++i) {
            ans.push_back(getChar());
        }
        if (!ok) cout << "NO" << '\n';
        else cout << "YES" << '\n' << ans << '\n'; 
	}
	return 0;
}
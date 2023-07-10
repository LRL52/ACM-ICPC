/*** 
 * @Author: LRL52
 * @Date: 2023-05-19 22:39:51
 * @LastEditTime: 2023-05-19 22:40:59
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> (s + 1);
        set<string> S;
        for (int i = 1; i < n; ++i) {
            string t;
            t.push_back(s[i]);
            t.push_back(s[i + 1]);
            S.insert(t);
        }
        cout << S.size() << '\n';
	}
	return 0;
}
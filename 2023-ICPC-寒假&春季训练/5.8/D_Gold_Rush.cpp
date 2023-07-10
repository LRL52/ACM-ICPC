/*** 
 * @Author: LRL52
 * @Date: 2023-05-08 19:47:54
 * @LastEditTime: 2023-05-08 19:50:54
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
int n, m;

void dfs(int x, map<int, int> &f) {
    if (f.find(x) != f.end()) return;
    f[x] = 1;
    if (x % 3 == 0) {
        dfs(x / 3, f);
        dfs(x / 3 * 2, f);
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        cin >> n >> m;
        if (m > n) {
            puts("NO");
            continue;
        }
        map<int, int> f;
        dfs(n, f);
        puts(f.find(m) != f.end() ? "YES" : "NO");
	}
	return 0;
}
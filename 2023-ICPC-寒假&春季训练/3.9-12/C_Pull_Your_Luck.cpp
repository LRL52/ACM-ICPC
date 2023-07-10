#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, vis[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
        int n, x, p;
		cin >> n >> x >> p;
        for(int i = 0; i < n; ++i) vis[i] = 0;
        for(int i = 1; i <= min(p, 2 * n); ++i) {
            x += i;
            x %= n;
            vis[x] = 1;
        }
        puts(vis[0] ? "Yes" : "No");
	}
	return 0;
}
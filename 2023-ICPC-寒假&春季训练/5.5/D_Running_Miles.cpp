#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e5 + 55, inf = 0x3f3f3f3f;
int n;
int a[N], b[N], c[N], f[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            b[i] = a[i] + i;
            c[i] = a[i] - i;
        }
        int maxv = b[1];
        for (int i = 2; i <= n; ++i) {
            if (i == 2) f[i] = maxv + a[i];
            else f[i] = max(f[i - 1], maxv + a[i]);
            maxv = max(maxv, b[i]);
        }
        int ans = a[1] + a[2] + a[3] - 2;
        for (int i = 3; i <= n; ++i) {
            ans = max(ans, f[i - 1] + c[i]);
        }
        cout << ans << '\n';
	}
	return 0;
}
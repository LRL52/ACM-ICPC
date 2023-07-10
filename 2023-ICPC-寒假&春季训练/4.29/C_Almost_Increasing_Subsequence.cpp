#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 200000 + 55, inf = 0x3f3f3f3f;
int n, Q, a[N], st[N], ed[N], sum[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; Task = 1;
    // cin >> Task;
	while(Task--) { 
		cin >> n >> Q;
        for (int i = 1; i <= n; ++i) cin >> a[i], st[i] = ed[i] = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            st[i] = 1;
            while (j < n && a[j + 1] <= a[j]) ++j;
            ed[j] = 1;
            // printf("i = %d %d
        }
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1];
            if (st[i] || ed[i])
                ++sum[i];
            // printf("sum[%d] = %d\n", i, sum[i]);
        }
        for (int i = 1; i <= Q; ++i) {
            int l, r;
            cin >> l >> r;
            int res = sum[r] - sum[l - 1];
            if (!st[l] && !ed[l]) ++res;
            if (l != r &&  !st[r] && !ed[r]) ++res;
            cout << res << '\n';
        }
	}
	return 0;
}
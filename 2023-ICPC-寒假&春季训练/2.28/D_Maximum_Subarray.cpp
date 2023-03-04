//ID: LRL52  Date: 2023.2.28
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int a[N], head[N], q[N];
i64 sum[N], g[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
		int n, K; i64 X;
        cin >> n >> K >> X;
        i64 ans = 0;
        sum[0] = 0;
        rep(i, 1, n) cin >> a[i], sum[i] = sum[i - 1] + a[i];
        rep(i, 0, n) {
            g[i] = i * X - sum[i];
        }
        for(int k = 0; k <= K; ++k) {
            int head = 1, tail = 0;
            // q[++tail] = 0;
            for(int i = 0; i <= n; ++i) {
                while(head <= tail && q[head] < K - k + i - n) ++head;
                if(i - k >= 0) {
                    int j = i - k;
                    while(head <= tail && g[q[tail]] <= g[j]) --tail;
                    q[++tail] = j;
                }
                if(head <= tail) {
                    auto res = sum[i] - i * X + 2LL * k * X + g[q[head]];
                    ans = max(ans, res);
                }
            }
        }
        cout << ans << '\n';
	}
	return 0;
}
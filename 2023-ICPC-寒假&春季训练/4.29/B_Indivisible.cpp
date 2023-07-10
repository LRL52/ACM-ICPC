/*** 
 * @Author: LRL52
 * @Date: 2023-04-29 22:57:56
 * @LastEditTime: 2023-04-29 22:58:57
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
int n, a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
		if (n == 1) {
			printf("1\n");
            continue;
        }
        if (n % 2 == 1) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; ++i) a[i] = i;
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; i += 2) swap(a[i], a[i + 1]);
        for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
        puts("");
	}
	return 0;
}
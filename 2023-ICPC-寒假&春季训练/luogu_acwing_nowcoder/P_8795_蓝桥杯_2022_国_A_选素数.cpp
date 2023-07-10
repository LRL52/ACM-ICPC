/*** 
 * @Author: LRL52
 * @Date: 2023-06-09 18:16:29
 * @LastEditTime: 2023-06-09 18:41:22
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int vmin[N], vmax[N];
vector<int> prime;

void Euler(int MAXN) {
    vmin[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        if (!vmin[i]) {
            vmin[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; prime[j] <= MAXN / i; ++j) {
            vmin[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) {
                break;
            } 
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("P8795.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
    if (n == 1) {
        puts("-1");
        return 0;
    }
    Euler(n);
    if (vmin[n] == n) {
        puts("-1");
        return 0;
    }
    vmax[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (vmin[i] == i) vmax[i] = i;
        else vmax[i] = vmax[i / vmin[i]];
    }
    auto l = n - vmax[n] + 1, ans = n;
    for (int i = l; i <= n; ++i) {
        if (vmin[i] != i)
            ans = min(ans, i - vmax[i] + 1);
    }
    cout << ans << '\n';
	return 0;
}
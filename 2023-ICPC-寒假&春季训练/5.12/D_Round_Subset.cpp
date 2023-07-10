/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:44:05
 * @LastEditTime: 2023-05-12 21:38:57
 */
#include <bits/stdc++.h>
#include <cstdio>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 205, inf = 0x3f3f3f3f;
int n, K;
int _5[N], _2[N];
int f[2][N][5005];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> K;
    for (int i = 1; i <= n; ++i) {
        i64 x; cin >> x;
        while (x % 2 == 0) x /= 2, _2[i]++;
        while (x % 5 == 0) x /= 5, _5[i]++;
    }
    memset(f, -1, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int now = i & 1, lst = now ^ 1;
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k <= 5000; ++k) {
                if (j > 0 && k >= _5[i] && f[lst][j - 1][k - _5[i]] != -1) {
                    f[now][j][k] = max(f[lst][j - 1][k - _5[i]] + _2[i], f[lst][j][k]);
                } else if (f[lst][j][k] != -1) {
                    f[now][j][k] = f[lst][j][k];
                } else {
                    f[now][j][k] = -1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 5000; ++i) {
        ans = max(ans, min(i, f[n & 1][K][i]));
    }
    cout << ans << '\n';
    // printf("%.2lf M\n", (double)sizeof(f) / (1 << 20));
	return 0;
}
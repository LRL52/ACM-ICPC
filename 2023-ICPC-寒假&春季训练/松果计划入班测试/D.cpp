/*** 
 * @Author: LRL52
 * @Date: 2023-07-01 19:53:40
 * @LastEditTime: 2023-07-01 20:04:05
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, m;
int a[N][N];
char s[N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

pii Solve(char op, pii now) {
    int k = 0;
    if (op == 'U') k = 0;
    if (op == 'R') k = 1;
    if (op == 'D') k = 2;
    if (op == 'L') k = 3;
    auto &[x, y] = now;
    while (1) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny]) break;
        x = nx, y = ny;
    }
    // printf("debug: %d %d\n", now.first, now.second);
    return now;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int sx, sy, K;
    cin >> n >> m >> sx >> sy >> K;
    for (int i = 1; i <= K; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    cin >> (s + 1);
    int n = strlen(s + 1);
    pii now = {sx, sy};
    for (int i = 1; i <= n; ++i) {
        now = Solve(s[i], now);
    } 
    cout << now.first << " " << now.second << '\n';
	return 0;
}
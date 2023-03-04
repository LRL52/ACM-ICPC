//ID: LRL52  Date: 2023.2.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e3 + 55, M = 2e3 + 55;
LL INF = 1e12;
const int dx[] = { 1, 0 };
const int dy[] = { 0, 1 };
int a[N][N], ans, n;
LL K;

void dfs(int i, int j, LL nowsum, LL mss, int step) {
    if(mss > K) return;
    if(step == 2 * n) {
        if(mss == K) ++ans;
        return;
    }
    if(i > n || j > n) return;
    // printf("i = %d, j = %d\n", i, j);
    // for(int k = 0; k < 2; ++k) {
        LL bak = nowsum;
        nowsum += a[i][j];
        LL t = nowsum;
        if(nowsum < 0) nowsum = 0;
        dfs(i + 1, j, nowsum, max(mss, t), step + 1);
        dfs(i, j + 1, nowsum, max(mss, t), step + 1);
        nowsum = bak;
    // }
}

signed main() {
    // freopen("J.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> K;
    rep(i, 1, n)
        rep(j, 1, n)
            cin >> a[i][j];
    dfs(1, 1, 0, -INF, 1); 
    cout << ans / 2 << endl;
	vector<int> f(n, 1);
	return 0;
}
//ID: LRL52  Date: 2023.2.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, m, K;
LL sum[N][25];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> K;
    rep(i, 1, n) {
        int x;
        cin >> x;
        for(int j = 0; j < K; ++j) sum[i][j] = sum[i - 1][j];
        sum[i][i % K] += x;
    }
    cin >> m;
    rep(i, 1, m) {
        int l, r;
        cin >> l >> r;
        vector<LL> a(K);
        for(int j = 0; j < K; ++j) a[j] = sum[r][j] - sum[l - 1][j];
        if(a == vector<LL>(K, a[0])) puts("Yes");
        else puts("No");
    } 
	return 0;
}

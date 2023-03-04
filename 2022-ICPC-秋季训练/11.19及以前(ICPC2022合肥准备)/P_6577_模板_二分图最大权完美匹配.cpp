//ID: LRL52  Date: 2022.11.17
#pragma GCC optimze(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
#define int long long
const int N = 505, _inf = 0xc1c1c1c1, inf = 0x3f3f3f3f;
int n, m, delta;
int W[N][N], la[N], lb[N], va[N], vb[N], match[N];
int dfs(int x){
    va[x] = 1;
    rep(y, 1, n){
        if(!vb[y])
            if(la[x] + lb[y] - W[x][y] == 0){
                vb[y] = 1;
                if(!match[y] || dfs(match[y])){
                    match[y] = x;
                    return 1;
                }
            }
            // else delta = min(delta, la[x] + lb[y] - W[x][y]);
    }
    return 0;
}

signed main() {
    freopen("P6577_6.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; int x, y, z;
    memset(W, -0x3f, sizeof(W));
    rep(i, 1, m) {
        cin >> x >> y >> z;
        W[x][y] = z;
    }
    rep(i, 1, n){
        la[i] = _inf;
        lb[i] = 0;
        rep(j, 1, n)
            la[i] = max(la[i], W[i][j]);
    }
    rep(_i, 1, n){
        while(1){
            memset(va, 0, sizeof va);
            memset(vb, 0, sizeof vb);
            if(dfs(_i)) break;
            delta = inf;
            for (int i=1;i<=n;i++)
            {
                if (!va[i]) continue;
                for (int j=1;j<=n;j++)
                {
                    if (vb[j]) continue;
                    delta = min(delta, la[i] + lb[j] - W[i][j]);
                }
            }
            rep(j, 1, n){
                if(va[j]) la[j] -= delta;
                if(vb[j]) lb[j] += delta;
            }
            //printf("delta = %d\n", delta);
        }
    }
    LL ans = 0;
    rep(i, 1, n) ans += W[match[i]][i];
    printf("%lld\n", ans);
    rep(i, 1, n) printf("%lld ", match[i]);
	return 0;
} 
    
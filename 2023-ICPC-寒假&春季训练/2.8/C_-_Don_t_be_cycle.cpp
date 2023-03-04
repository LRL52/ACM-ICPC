//ID: LRL52  Date: 2023.2.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, m;
int vis[N];

int fa[N];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; int ans = 0;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        int x, y;
        cin >> x >> y;
        // if(!vis[x]) vis[x] = 1, ++cnt;
        // if(!vis[y]) vis[y] = 1, ++cnt;
        int f1 = find(x), f2 = find(y);
        if(f1 != f2) fa[f1] = f2;
        else ++ans;
    }
    // cout << max(m - (cnt - 1), 0) << '\n'; 
	cout << ans << '\n';
    return 0;
}
